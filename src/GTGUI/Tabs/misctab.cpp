#include "misctab.h"

void Misc::RenderTab()
{
    ImGui::BeginChild("Misc", ImVec2(0, 0), true);
    {
        ImGui::Checkbox("Clean screenshots", &Settings::ScreenshotCleaner::enabled);
    }
	ImGui::EndChild();
}
