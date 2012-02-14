
#include "AviatorBinding.h"

#include "Drawing.tolua.h"

void AviatorBinding::open(lua_State *L) {
	tolua_Drawing_open(L);
}