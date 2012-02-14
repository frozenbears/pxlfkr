
#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class LuaValue {

public:
	//virtual ~LuaValue() {};
	virtual void push(lua_State *L) = 0;
};