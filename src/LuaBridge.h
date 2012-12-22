
#include "LuaState.h"
#include "OscMessage.h"
#include "cinder/Cinder.h"


class LuaBridge {
	
public:
	//hooks for the run loop
	void setup();
	void update();
	void draw();
	
	//convenience method for loading lua scripts into the state
	void load(std::string fname);
	
	//passing OSC messages
	void handleMessage(cinder::osc::Message message);
	
private:
	LuaState lua;
};