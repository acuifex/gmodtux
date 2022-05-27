#pragma once

#include "ImGUI/backends/imgui_impl_sdl.h"
//#include "SDK/IInputSystem.h"

namespace Shortcuts
{
    void PollEvent(SDL_Event* event);
//    void SetKeyCodeState(ButtonCode_t code, bool bPressed);
}
