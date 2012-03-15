

#include "LuaBridge.h"
#include "cinder/app/App.h"
#include "cinder/CinderResources.h"

#include "OSCMessageTable.h"
#include "CoreBindings.h"

using namespace ci;
using namespace ci::app;

void LuaBridge::load(std::string fname) {
	lua.doFile(App::getResourcePath(fname));
}

void LuaBridge::hello() {
   load("test.lua");
}

void LuaBridge::setup() {
	CoreBindings bindings;
	lua.bind(bindings);
	
	load("core.lua");
	lua.callFunction("setup");
}

void LuaBridge::update() {
	lua.callFunction("update");
}

void LuaBridge::draw() {
	lua.callFunction("draw");
}

void LuaBridge::handleMessage(osc::Message message) {
	OSCMessageTable table = OSCMessageTable(message);
	lua.callFunction("osc", table);
}
