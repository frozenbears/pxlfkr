
#include "CoreBindings.h"

#include "Drawing.tolua.h"

void CoreBindings::open(lua_State *L) {
	tolua_Drawing_open(L);
}