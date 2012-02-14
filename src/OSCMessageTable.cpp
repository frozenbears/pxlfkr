
#include <string>
#include <iostream>

#include "OSCMessageTable.h"

OSCMessageTable::OSCMessageTable(cinder::osc::Message m) {
	message = m;
}

void OSCMessageTable::push(lua_State *L) {
	
	lua_newtable(L); //create a table, push it on the stack
	
	//set the "address" field
	lua_pushstring(L, "address");
	lua_pushstring(L, message.getAddress().c_str());
	lua_settable(L, -3); //this pops the key and value
	
	for (int i = 0; i < message.getNumArgs(); i++) {
		
		if (message.getArgType(i) == cinder::osc::TYPE_INT32){
			try {
				lua_pushnumber(L, (double)i+1);
				lua_pushnumber(L, (double)message.getArgAsInt32(i));
				lua_settable(L, -3);				
			}
			catch (...) {
				std::cout << "OSCMessageTable: Exception reading argument as int32" << std::endl;
			}
			
		}else if (message.getArgType(i) == cinder::osc::TYPE_FLOAT){
			try {
				lua_pushnumber(L, (double)i+1);
				lua_pushnumber(L, (double)message.getArgAsFloat(i));
				lua_settable(L, -3);
				
			}
			catch (...) {
				std::cout << "OSCMessageTable: Exception reading argument as float" << std::endl;
			}
		}else if (message.getArgType(i) == cinder::osc::TYPE_STRING){
			try {
				lua_pushnumber(L, (double)i+1);
				lua_pushstring(L, message.getArgAsString(i).c_str());
				lua_settable(L, -3);				
			}
			catch (...) {
				std::cout  << "OSCMessageTable: Exception reading argument as string" << std::endl;
			}
			
		}
	}
	
	
}