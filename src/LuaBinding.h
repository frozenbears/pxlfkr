
#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class LuaBinding {
	
public:
	virtual void open(lua_State *L) = 0;
};