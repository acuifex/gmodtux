#include "hooks.h"
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_impl_sdl.h"
#include "../ATGUI/SegoeUI.h"

void Hooks::ShowPixels(void *thisptr, CShowPixelsParams *params)
{
    if (!params->m_noBlit){
        return launcherMgrVMT->GetOriginalMethod<ShowPixelsFn>(29)(thisptr, params);
    }

    static SDL_Window* window = reinterpret_cast<SDL_Window*>(launcherMgr->GetWindowRef());

    static PseudoGLContextPtr original_context = launcherMgr->GetMainContext();
    static PseudoGLContextPtr user_context = NULL;

    // setup context on first run
    if( !user_context ) {
        user_context = launcherMgr->CreateExtraContext();
        ImGui_ImplSdl_Init(window);

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

        io.Fonts->Build();
    }

    // Switch to our context
    launcherMgr->MakeContextCurrent(user_context);

    // Start ImGui rendering.
    ImGui_ImplSdl_NewFrame(window);

    ImGui::GetIO().MouseDrawCursor = UI::isVisible;
    ImGui::GetIO().WantCaptureMouse = UI::isVisible;
    ImGui::GetIO().WantCaptureKeyboard = UI::isVisible;

    // Handle input while menu is active
    if ( UI::isVisible && !SetKeyCodeState::shouldListen ) {
        SDL_Event event = {};

        while ( SDL_PollEvent(&event) ) {
            if ( event.key.keysym.sym == SDLK_INSERT && event.type == SDL_KEYDOWN )
                UI::SetVisible(!UI::isVisible);
            ImGui_ImplSdl_ProcessEvent(&event);
        }
    }

    Draw::ImStart();
    UI::WaterMark();
    Draw::ImEnd();

    UI::SetupColors();
    UI::SetupWindows();

    ImGui::GetCurrentContext()->Font->DisplayOffset = ImVec2(0.f, 0.f);

    ImGui::Render();

    launcherMgr->MakeContextCurrent(original_context);

    launcherMgrVMT->GetOriginalMethod<ShowPixelsFn>(29)(thisptr, params);
}