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
	void* vtable;
	void* luaState;
};

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
