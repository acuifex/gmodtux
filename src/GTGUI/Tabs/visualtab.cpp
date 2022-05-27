#include "visualtab.h"

void Visual::RenderTab()
{
	ImGui::BeginChild("Visual", ImVec2(0, 0), true);
	{
		ImGui::Checkbox("ESP", &Settings::ESP::enabled);
	}
	ImGui::EndChild();
}