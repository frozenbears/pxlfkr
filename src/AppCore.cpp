
#include "AppCore.h"
#include "OscMessageTable.h"

//--------------------------------------------------------------
void AppCore::setup() {

    oscReceiver.setup(12345);

	ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);

    ofSetWindowTitle("p x l f k r");
    ofSetFrameRate(60);
    ofSetEscapeQuitsApp(false);
	
	// init the lua state
	lua.init();
	
	// listen to error events
	lua.addListener(this);
	
	// bind the OF api to the lua state
	lua.bind<ofxLuaBindings>();
	
	// load the pf core
	lua.doScript("scripts/core.lua");
	
	// call the core setup function
	lua.scriptSetup();
}

//--------------------------------------------------------------
void AppCore::update() {
    // call the core update function
	lua.scriptUpdate();
    while(oscReceiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
        oscReceiver.getNextMessage(&m);
        OscMessageTable messageTable = OscMessageTable(m);

        // pass it to the scripting layer
        lua_getglobal(lua, "osc");
        messageTable.push(lua);
        if(lua_pcall(lua, 1, 0, 0)) {
            std::cerr << "Error calling osc function:\n";
            std::cerr << lua_tostring(lua, -1) << std::endl;
            lua_pop(lua, 1);
        }
	}
}

//--------------------------------------------------------------
void AppCore::draw() {
	// call the core draw function
	lua.scriptDraw();
}

//--------------------------------------------------------------
void AppCore::exit() {
	// call the core exit function
	lua.scriptExit();
	
	// clear the lua state
	lua.clear();
}

//--------------------------------------------------------------
void AppCore::keyPressed(int key) {
	switch(key) {
		case OF_KEY_ESC:
			ofToggleFullscreen();
			break;
    }
	
	lua.scriptKeyPressed(key);
}

//--------------------------------------------------------------
void AppCore::mouseMoved(int x, int y) {
	lua.scriptMouseMoved(x, y);
}

//--------------------------------------------------------------
void AppCore::mouseDragged(int x, int y, int button) {
	lua.scriptMouseDragged(x, y, button);
}

//--------------------------------------------------------------
void AppCore::mousePressed(int x, int y, int button) {
	lua.scriptMousePressed(x, y, button);
}

//--------------------------------------------------------------
void AppCore::mouseReleased(int x, int y, int button) {
	lua.scriptMouseReleased(x, y, button);
}

//--------------------------------------------------------------
void AppCore::errorReceived(string& msg) {
    std::cerr << "Error: " << msg << endl;
}
