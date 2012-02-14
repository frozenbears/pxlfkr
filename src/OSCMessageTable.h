
#include "LuaValue.h"
#include "OscMessage.h"

class OSCMessageTable : public LuaValue {
	
public:
	
	OSCMessageTable(cinder::osc::Message m);
	
	void push(lua_State *L);
	
	cinder::osc::Message message;
};