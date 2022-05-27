#include "gtgui.h"

#include "Windows/main.h"
#include "Windows/colors.h"

bool UI::isVisible = false;

bool Settings::ScreenshotCleaner::enabled = false;

// stolen from my fuzion config
ColorVar Settings::UI::mainColor = ImColor(0.0088f, 0.0f, 0.1658f, 0.6733f);
ColorVar Settings::UI::bodyColor = ImColor(0.0434f, 0.0333f, 0.1105f, 0.5829f);
ColorVar Settings::UI::fontColor = ImColor(1.0f, 1.0f, 1.0f, 1.0f);
ColorVar Settings::UI::accentColor = ImColor(0.1529f, 0.4156f, 0.8588f, 1.0f);
// Window Position/Size Defaults

int Settings::UI::Windows::Main::sizeX = 960;
int Settings::UI::Windows::Main::sizeY = 645;
int Settings::UI::Windows::Main::posX = 20;
int Settings::UI::Windows::Main::posY = 20;
bool Settings::UI::Windows::Main::open = false;
bool Settings::UI::Windows::Main::reload = false;

int Settings::UI::Windows::Colors::sizeX = 540;
int Settings::UI::Windows::Colors::sizeY = 325;
int Settings::UI::Windows::Colors::posX = 540;
int Settings::UI::Windows::Colors::posY = 325;
bool Settings::UI::Windows::Colors::open = false;
bool Settings::UI::Windows::Colors::reload = false;



#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

void SetupMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8 * 2.0f, 4 * 2.0f));

        ImGui::Selectable("Main Window", &Main::showWindow, 0, ImVec2(ImGui::CalcTextSize("Main Window", NULL, true).x, 0.0f));
        ImGui::SameLine();
        ImGui::Selectable("Colors Window", &Colors::showWindow, 0, ImVec2(ImGui::CalcTextSize("Colors Window", NULL, true).x, 0.0f));
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
        Main::RenderWindow();
	    Colors::RenderWindow();
    }
}
