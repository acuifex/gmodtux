#include "misctab.h"

void Misc::RenderTab()
{
    ImGui::Columns(2, NULL, true);
    {
        ImGui::BeginChild("COL1", ImVec2(0, 0), true);
        {
            ImGui::Text("ESP");
            ImGui::BeginChild("ESP", ImVec2(0, 0), true);
            ImGui::Text("enabled");
            ImGui::Separator();
            ImGui::Columns(1);
	        ImGui::Checkbox("##ESPENABLED", &Settings::ESP::enabled);
            ImGui::EndChild();
            ImGui::EndChild();
        }
    }

    ImGui::NextColumn();
    {
        ImGui::BeginChild("Chams", ImVec2(0, 0), true);
        {
            ImGui::Columns(1);
            ImGui::Text("Other Visual Settings");
            ImGui::Separator();

            ImGui::Checkbox("Clean screenshots", &Settings::ScreenshotCleaner::enabled);

            ImGui::Columns(1);
            ImGui::Separator();

            ImGui::EndChild();
        }
    }
    ImGui::Columns(1);
}
