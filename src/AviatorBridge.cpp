

#include "AviatorBridge.h"
#include "cinder/app/App.h"
#include "cinder/CinderResources.h"

#include "OSCMessageTable.h"
#include "AviatorBinding.h"

using namespace ci;
using namespace ci::app;

void AviatorBridge::load(std::string fname) {
	lua.doFile(App::getResourcePath(fname));
}

void AviatorBridge::hello() {
   load("test.lua");
}

void AviatorBridge::setup() {
	AviatorBinding binding;
	lua.bind(binding);
	
	load("core.lua");
	lua.callFunction("setup");
}

void AviatorBridge::update() {
	lua.callFunction("update");
}

void AviatorBridge::draw() {
	lua.callFunction("draw");
}

void AviatorBridge::handleMessage(osc::Message message) {
	OSCMessageTable table = OSCMessageTable(message);
	lua.callFunction("handleMessage", table);
}
