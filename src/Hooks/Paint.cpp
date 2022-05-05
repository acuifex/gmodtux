#include "hooks.h"

#include "../Utils/draw.h"
#include "../Hacks/esp.h"

#include <mutex>

extern StartDrawingFn StartDrawing;
extern FinishDrawingFn FinishDrawing;

int Paint::engineWidth;
int Paint::engineHeight;

typedef void (*PaintFn) (void*, PaintMode_t);

void Hooks::Paint(void* thisptr, PaintMode_t mode)
{
	engineVGuiVMT->GetOriginalMethod<PaintFn>(14)(thisptr, mode);
	
	// TODO: check these function indexes
	engine->GetScreenSize(Paint::engineWidth,Paint::engineHeight );
	
	if (Settings::ScreenshotCleaner::enabled && engine->IsTakingScreenshot()) {
		cvar->ConsoleColorPrintf(ColorRGBA(255, 0, 0), "Taking a screenshot\n");
		return;
	}
	
	if (mode & PAINT_UIPANELS)
	{
		std::unique_lock<std::mutex> lock( Draw::m_draw );
		int prevRecords = Draw::drawRequests.size(); // # of requests from last call
		lock.unlock();
		
		// call functions and stuff here
		ESP::Paint();
		
		lock.lock();
		Draw::drawRequests.erase( Draw::drawRequests.begin( ), Draw::drawRequests.begin( ) + prevRecords );
	}
}

void Hooks::PaintImGui()
{
    std::unique_lock<std::mutex> lock( Draw::m_draw );

    float width = (float)Paint::engineWidth;
    float height = (float)Paint::engineHeight;
    float imWidth = ImGui::GetWindowWidth();
    float imHeight = ImGui::GetWindowHeight();

    for( const DrawRequest &value : Draw::drawRequests ){
        /* Convert in case there are stretched resolution users - DONT write to original struct! */
        int x0 = (int)((value.x0 / width) * imWidth);
        int y0 = (int)((value.y0 / height) * imHeight);
        int x1 = (int)((value.x1 / width) * imWidth);
        int y1 = (int)((value.y1 / height) * imHeight);
		//TODO: fix a crash due to a racing condition or something
		//EDIT: should should be fixed? changed local mutex to Draw::m_draw
		//(gdb) backtrace
	    // #0  0x00007f89899489e3 in Hooks::PaintImGui() () at /home/acuifex/Projects/gmodtux/src/Hooks/Paint.cpp:61
	    // #1  0x00007f898998c8bd in SDL2::SwapWindow(SDL_Window*) (window=0xb45030) at /home/acuifex/Projects/gmodtux/src/glhook.cpp:80
	    // #2  0x00007f8aac07b154 in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/launcher_client.so
	    // #3  0x00007f8aab21fdbb in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/libtogl_client.so
	    // #4  0x00007f8aab21380c in IDirect3DDevice9::Present(_RECT const*, _RECT const*, void*, RGNDATA const*) ()
	    //     at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/libtogl_client.so
	    // #5  0x00007f8a92fffe14 in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/shaderapidx9_client.so
	    // #6  0x00007f8a948bf86b in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/materialsystem_client.so
	    // #7  0x00007f8a948c96da in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/materialsystem_client.so
	    // #8  0x00007f8a948c9886 in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/materialsystem_client.so
	    // #9  0x00007f8a948a56b8 in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/materialsystem_client.so
	    // #10 0x00007f8a948b07f1 in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/materialsystem_client.so
	    // #11 0x00007f8aabb86a84 in  () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/libvstdlib_client.so
	    // #12 0x00007f8aabdfdefb in CThread::ThreadProc(void*) () at /hdd/SteamLibrary/steamapps/common/GarrysMod/bin/linux64/libtier0_client.so
	    // #13 0x00007f8aac4a9609 in start_thread (arg=<optimized out>) at pthread_create.c:477
	    // #14 0x00007f8aac3ce163 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95
	    // (gdb) print value.type
	    // $1 = 379210144
        switch( value.type ){
            case DRAW_LINE:
                Draw::ImLine( ImVec2( x0, y0 ), ImVec2( x1, y1 ), value.color );
                break;
            case DRAW_RECT:
                Draw::ImRect( x0, y0, x1, y1, value.color );
                break;
            case DRAW_RECT_FILLED:
                Draw::ImRectFilled( x0, y0, x1, y1, value.color );
                break;
            case DRAW_CIRCLE:
                Draw::ImCircle( ImVec2( x0, y0 ), value.color, value.circleRadius, value.circleSegments, value.thickness );
                break;
            case DRAW_CIRCLE_FILLED:
                Draw::ImCircleFilled( ImVec2( x0, y0 ), value.color, value.circleRadius, value.circleSegments );
                break;
/*            case DRAW_CIRCLE_3D:
                Draw::ImCircle3D( value.pos, value.circleSegments, value.circleRadius, value.color );
                break;*/
            case DRAW_TEXT:
                Draw::ImText( ImVec2( x0, y0 ), value.color, value.text, nullptr, 0.0f, nullptr, value.fontflags );
                break;
        }
    }
}