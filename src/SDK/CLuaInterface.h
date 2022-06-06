#pragma once

enum LuaInterfaceType
{
    LUAINTERFACE_CLIENT = 0,
    LUAINTERFACE_SERVER = 1,
    LUAINTERFACE_MENU = 2
};

class CLuaInterface
{
public:
	void ExecuteFile(const char* filename, bool bLogErrorsToConsole)
	{
		// (**(code **)(*cl_lua_obj + 0x308))(cl_lua_obj,filename,1,1,"!UNKNOWN",1);
		//ulong CLuaInterface::execute_lua(CLuaInterface *this,char *filename,undefined param_3,char param_4,char *str_UNKNOWN,undefined8 param_6)
		// no clue what other parameters mean
		
		// call by cl_openscript_cl handler can be found by xrefing "Running script %s...\n" in client_client.so
		// function itself can be found by xrefing "Couldn\'t include file \'%s\' - Not a .lua file! (%s)\n" in lua_shared_client.so
		typedef void (* ExecuteFile)(void*, const char*, int, int, const char*, int);
		return getvfunc<ExecuteFile>(this, 97)(this, filename, 1, bLogErrorsToConsole, "!UNKNOWN", 1);
	}
	void* vtable; //0x0000
	void* luaState; //0x0008
	char pad_0010[344]; //0x0010
	// setting this to true bypasses sv_cheats and sv_allowcslua checks
	bool bypass_restrictions; //0x0168
};

// https://www.unknowncheats.me/forum/garry-s-mod/269891-fixed-sniff_glua-lua-script-executor-garrys-mod-source-binaries.html

class CLuaShared
{
public:
	CLuaInterface* GetLuaInterface(LuaInterfaceType type)
	{
	    typedef CLuaInterface* (* oGetLuaInterface)(void*, LuaInterfaceType);
	    return getvfunc<oGetLuaInterface>(this, 7)(this, type);
    }
	void* vtable;
};
