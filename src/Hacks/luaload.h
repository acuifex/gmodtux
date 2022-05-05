#pragma once

#include "../settings.h"
#include "../interfaces.h"

namespace LuaLoad
{
    //Hooks
    void CreateMove(CUserCmd* cmd);
	// TODO: this probably needs to be run in a specific thread
	void ExecuteLua(const char* path);
}