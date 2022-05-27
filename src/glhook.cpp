#include "glhook.h"

#include "interfaces.h"
#include "shortcuts.h"
#include "GTGUI/gtgui.h"
#include "GTGUI/SegoeUI.h"
#include "Hooks/hooks.h"
// #include "ImGUI/fonts/KaiGenGothicCNRegular.h"
#include "ImGUI/backends/imgui_impl_opengl2.h"
#include "Utils/draw.h"

#include <SDL.h>

SDL_GLContext context = nullptr;

void SDL2::SwapWindow(SDL_Window* window)
{
	
    static SDL_GL_SwapWindow_t oSDL_GL_SwapWindow = reinterpret_cast<SDL_GL_SwapWindow_t>(oSwapWindow);

    static SDL_GLContext original_context = SDL_GL_GetCurrentContext();
    if (!context)
    {
        context = SDL_GL_CreateContext(window);
	    ImGui::CreateContext();
	    // wrapper around ImGui_ImplSDL2_Init
	    ImGui_ImplSDL2_InitForOpenGL(window, context);
	    ImGui_ImplOpenGL2_Init();
	
	    ImWchar SegoeUI_ranges[] = {
			    0x0020, 0x007E, // Basic Latin
			    0x00A0, 0x00FF, // Latin-1 Supplement
			    0x0100, 0x017F, // Latin Extended-A
			    0x0180, 0x024F, // Latin Extended-B
			    0x0370, 0x03FF, // Greek and Coptic
			    0x0400, 0x04FF, // Cyrillic
			    0x0500, 0x052F, // Cyrillic Supplementary
			    0
	    };
		
	    ImGuiIO& io = ImGui::GetIO();
	    ImFontConfig config;
	
	    // Add SegoeUI as default font
	    io.Fonts->AddFontFromMemoryCompressedTTF(SegoeUI_compressed_data, SegoeUI_compressed_size, 18.0f, &config, SegoeUI_ranges);
	
	    // Enable MergeMode and add additional fonts
	    config.MergeMode = true;
		config.GlyphOffset = ImVec2(0.f, 0.f);
	    io.Fonts->Build();
    }

    SDL_GL_MakeCurrent(window, context);
	
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

    ImGui::GetIO().MouseDrawCursor = UI::isVisible;
    ImGui::GetIO().WantCaptureMouse = UI::isVisible;
    ImGui::GetIO().WantCaptureKeyboard = UI::isVisible;

    if (UI::isVisible && !SetKeyCodeState::shouldListen)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
	        if (event.type == SDL_QUIT)
		        return;
	
	        ImGui_ImplSDL2_ProcessEvent(&event);
        }
    }

    Draw::ImStart();
    UI::WaterMark();
    Hooks::PaintImGui(); // Process ImGui Draw Commands
    Draw::ImEnd();

    UI::SetupColors();
    UI::SetupWindows();

    ImGui::Render();
	// i hope opengl2 renderer is the correct one.
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_MakeCurrent(window, original_context);
    oSDL_GL_SwapWindow(window);
}

void SDL2::UnhookWindow()
{
    *swapWindowJumpAddress = oSwapWindow;
	
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

    SDL_GL_DeleteContext(context);
}

int SDL2::PollEvent(SDL_Event* event)
{
    static SDL_PollEvent_t oSDL_PollEvent = reinterpret_cast<SDL_PollEvent_t>(oPollEvent);

    Shortcuts::PollEvent(event);

    return oSDL_PollEvent(event);
}

void SDL2::UnhookPollEvent()
{
    *polleventJumpAddress = oPollEvent;
}
