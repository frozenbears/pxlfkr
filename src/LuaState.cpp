
#include "LuaState.h"
#include <string>
#include <iostream>

LuaState::LuaState() {
	L = lua_open();
	luaL_openlibs(L);
};

bool LuaState::doFile(std::string filePath) {
	
	//no joy?
	if (luaL_dofile(L, filePath.c_str()) != 0) {
		//how come?
		std::cout << "Error reading file:  " << lua_tostring(L, -1) << "\n";
		lua_pop(L, 1);
		
		return false;
	}
	
	//rad!
	return true;
}

void LuaState::getGlobal(std::string gname) {
	lua_getglobal(L, gname.c_str());
}

bool LuaState::pcall(int args, int return_values) {
	
	if(lua_pcall(L, args, return_values, 0) != 0) {
		std::cout << "Error calling function: " << lua_tostring(L, -1) << "\n";
		lua_pop(L, 1);
		return false;
	}
	
	return true;
}

bool LuaState::callFunction(std::string fname) {
	getGlobal(fname);
	return pcall(0, 0);
}

bool LuaState::callFunction(std::string fname, LuaValue& value) {
	
	//place the function on the stack
	getGlobal(fname);
	
	//push the argument
	value.push(L);
	
	//do it
	return pcall(1, 0);
}

void LuaState::bind(LuaBinding &binding) {
	binding.open(L);
}

LuaState::~LuaState() {
	lua_close(L);
};