#include "luaload.h"

// https://www.unknowncheats.me/forum/garry-s-mod/269891-fixed-sniff_glua-lua-script-executor-garrys-mod-source-binaries.html

void CreateMove(CUserCmd* cmd) {

}

void LuaLoad::ExecuteLua(const char* path) {
	CLuaInterface* LuaInterface = luaShared->GetLuaInterface(LUAINTERFACE_CLIENT);
	if (!LuaInterface) {
		cvar->ConsoleDPrintf("Failed to get LuaInterface.\n");
		return;
	}
	
	if (!LuaInterface->luaState) {
		cvar->ConsoleDPrintf("Failed to get lua_State.\n");
		return;
	}
	
	// if (!*(uintptr_t*)(CLuaInterface + 0x2C)) {
	// Execute the Lua script provided.
	if (luaL_loadfile(LuaInterface->luaState, path) != 0) {
		cvar->ConsoleDPrintf("Failed to load file.\n");
		return;
	}
	if (lua_pcall(LuaInterface->luaState, 0, -1, 0) != 0) {
		cvar->ConsoleDPrintf("Failed to run file.\n");
		return;
	}
	cvar->ConsoleDPrintf("hi\n");
	// }
}
