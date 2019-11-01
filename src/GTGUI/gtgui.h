#pragma once

#include <list>
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_internal.h"
#include "../ImGUI/imgui_impl_sdl.h"
#include "../settings.h"
//#include "../Hacks/hacks.h"
#include "imgui.h"
#include "Windows/main.h"
#include "Tabs/visualstab.h"

namespace UI
{
    extern bool isVisible;

    void SetVisible(bool visible);
    void WaterMark( );
    void SetupColors();
    void SetupWindows();
    bool ColorPicker(float* col, bool alphabar);
    bool ColorPicker3(float col[3]);
    bool ColorPicker4(float col[4]);
    void KeyBindButton(ButtonCode_t* key);
    void UpdateWeaponSettings();
    void ReloadWeaponSettings();
}


inline void SetTooltip(const char* text)
{
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("%s", text);
}
