#include "misctab.h"
#include "../../SDK/CLuaInterface.h"

static char luaFilename[256] = "";

void Misc::RenderTab()
{
    ImGui::BeginChild("Misc", ImVec2(0, 0), true);
    {
        ImGui::Checkbox("Clean screenshots", &Settings::ScreenshotCleaner::enabled);
		ImGui::InputTextWithHint("##LUAFILENAME", "gmodtux.lua", luaFilename, 256);
		ImGui::SameLine();
		if (ImGui::Button("Execute lua")) {
			// running this in a swapwindow hook is possibly a bad idea, but whatever
			auto luainterface = luaShared->GetLuaInterface(LUAINTERFACE_CLIENT);
			if (luainterface){
				bool old_val = luainterface->bypass_restrictions;
				luainterface->bypass_restrictions = true;
				luainterface->ExecuteFile(luaFilename, true);
				luainterface->bypass_restrictions = old_val;
			}
			
		}
    }
	ImGui::EndChild();
}
