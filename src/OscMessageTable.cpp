
#include <string>
#include <iostream>

#include "OscMessageTable.h"

OscMessageTable::OscMessageTable(const ofxOscMessage& m) {
    message = m;
}

void OscMessageTable::push(lua_State *L) {

    lua_newtable(L); //create a table, push it on the stack

    //set the "address" field
    lua_pushstring(L, "address");
    lua_pushstring(L, message.getAddress().c_str());

    // pop the key and value
    lua_settable(L, -3);

    for (int i = 0; i < message.getNumArgs(); i++) {

        if (message.getArgType(i) == OFXOSC_TYPE_INT32){
            int32_t arg = message.getArgAsInt32(i);

            lua_pushnumber(L, (double_t)i+1);
            lua_pushnumber(L, (double_t)arg);
            lua_settable(L, -3);
        } else if (message.getArgType(i) == OFXOSC_TYPE_FLOAT){
            float_t arg = message.getArgAsFloat(i);

            lua_pushnumber(L, (double_t)i+1);
            lua_pushnumber(L, (double_t)arg);
            lua_settable(L, -3);

        } else if (message.getArgType(i) == OFXOSC_TYPE_STRING){
            string arg = message.getArgAsString(i);

            lua_pushnumber(L, (double_t)i+1);
            lua_pushstring(L, arg.c_str());
            lua_settable(L, -3);
        }
    }
}
