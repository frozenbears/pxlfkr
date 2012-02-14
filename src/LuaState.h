
#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "LuaValue.h"
#include "LuaBinding.h"

class LuaState {
	
public:
		
	bool doFile(std::string filePath);
	
	//push a global name onto the stack
	void getGlobal(std::string gname);
	
	//call the function on the stack
	bool pcall(int args, int return_values);
	
	//call a function with no arguments
	bool callFunction(std::string fname);
	
	//call a function with one argument
	bool callFunction(std::string fname, LuaValue &value);
	
	void bind(LuaBinding &binding);
	
	LuaState();
	~LuaState();
	
private:
	lua_State *L;
};