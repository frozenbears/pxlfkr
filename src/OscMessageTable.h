
#include "LuaValue.h"
#include "ofxOscMessage.h"

class OscMessageTable : public LuaValue {

public:

	OscMessageTable(const ofxOscMessage &m);

	void push(lua_State *L);

	ofxOscMessage message;
};
