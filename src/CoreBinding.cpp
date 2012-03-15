
#include "CoreBindings.h"

#include "Drawing.tolua.h"
#include "Text.tolua.h"

void CoreBindings::open(lua_State *L) {
	tolua_Drawing_open(L);
	tolua_Text_open(L);
}