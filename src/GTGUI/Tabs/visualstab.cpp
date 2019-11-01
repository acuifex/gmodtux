#include "visualstab.h"

void Visuals::RenderTab()
{
    const char* BoxTypes[] = { "Flat 2D", "Frame 2D", "Box 3D", "Hitboxes" };
    const char* TracerTypes[] = { "Bottom", "Cursor" };
    const char* BarTypes[] = { "Vertical Left", "Vertical Right", "Horizontal Below", "Horizontal Above", "Interwebz" };
    const char* BarColorTypes[] = { "Static", "Health Based" };
    const char* TeamColorTypes[] = { "Absolute", "Relative" };
    const char* ChamsTypes[] = { "Normal", "Normal - XQZ", "Flat", "Flat - XQZ" };
    const char* ArmsTypes[] = { "Default", "Wireframe", "None" };

    ImGui::Columns(2, NULL, true);
    {
        ImGui::Checkbox("Enabled", &Settings::ESP::enabled);
        ImGui::NextColumn();
        ImGui::Text("Only on Key");
//        UI::KeyBindButton(&Settings::ESP::key);
    }
    ImGui::Separator();

    ImGui::Columns(2, NULL, true);
    {
        ImGui::BeginChild("COL1", ImVec2(0, 0), true);
        {
            ImGui::Text("ESP");
            ImGui::BeginChild("ESP", ImVec2(0, 0), true);
            ImGui::Text("Type");
            ImGui::Separator();
            ImGui::Columns(1);
            ImGui::EndChild();
            ImGui::EndChild();
        }
    }

    ImGui::NextColumn();
    {
        ImGui::BeginChild("Chams", ImVec2(0, 0), true);
        {
            ImGui::Columns(1);
            ImGui::Separator();
            ImGui::Text("Skybox Changer");
            ImGui::Separator();
            ImGui::Checkbox("##SKYBOXENABLE", &Settings::SkyBox::enabled);
            ImGui::Separator();
            ImGui::Text("Other Visual Settings");
            ImGui::Separator();

            ImGui::Checkbox("No Sky", &Settings::NoFog::enabled);

            ImGui::Columns(1);
            ImGui::Separator();

            ImGui::EndChild();
        }
    }
    ImGui::Columns(1);
}
