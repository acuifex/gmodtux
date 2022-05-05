#include "gtgui.h"

bool UI::isVisible = false;

bool Settings::ScreenshotCleaner::enabled = false;

ColorVar Settings::UI::mainColor = ImColor(216, 157, 116, 255);
ColorVar Settings::UI::bodyColor = ImColor(240, 240, 240, 200);
ColorVar Settings::UI::fontColor = ImColor(0, 0, 0, 255);
ColorVar Settings::UI::accentColor = ImColor(87, 84, 83, 155);
// Window Position/Size Defaults

int Settings::UI::Windows::Main::sizeX = 960;
int Settings::UI::Windows::Main::sizeY = 645;
int Settings::UI::Windows::Main::posX = 20;
int Settings::UI::Windows::Main::posY = 20;

bool Settings::UI::Windows::Main::open = false;

bool Settings::UI::Windows::Main::reload = false;



#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

void SetupMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8 * 2.0f, 4 * 2.0f));

        ImGui::Selectable("Main Window", &Main::showWindow, 0, ImVec2(ImGui::CalcTextSize("Main Window", NULL, true).x, 0.0f));
        ImGui::SameLine();

        ImGui::SameLine(ImGui::GetWindowContentRegionMax().x-ImVec2(ImGui::CalcTextSize("Unload   ", NULL, true)).x);

        if( ImGui::Button("Unload   ", ImVec2(ImGui::CalcTextSize("Unload   ", NULL, true).x, 0.0f)) )
        {
//            Fuzion::SelfShutdown();
        }

        ImGui::PopStyleVar();
        ImGui::EndMainMenuBar();
    }
}

void UI::WaterMark( )
{
    if (UI::isVisible)
        return;

    Draw::ImText(ImVec2(4.f, 4.f), ImColor(255, 255, 255, 255), "gmodtux", NULL, 0.0f, NULL, ImFontFlags_Shadow);
}

void UI::SetVisible(bool visible)
{
    UI::isVisible = visible;
    cvar->FindVar("cl_mouseenable")->SetValue(UI::isVisible ? 0 : 1);
}

void UI::SetupWindows()
{
    if (UI::isVisible)
    {
        SetupMainMenuBar();

        ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(960, 645));
        Main::RenderWindow();
        ImGui::PopStyleVar();
    }
}
