/*
 * Copyright (c) 2012 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxLua for documentation
 *
 */
#include "AppCore.h"

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

        //pass it to the script layer

        // for debugging purposes:
        string msg_string;
        msg_string = m.getAddress();
        msg_string += ": ";
        for(int i = 0; i < m.getNumArgs(); i++){
            // get the argument type
            msg_string += m.getArgTypeName(i);
            msg_string += ":";
            // display the argument - make sure we get the right type
            if(m.getArgType(i) == OFXOSC_TYPE_INT32){
                msg_string += ofToString(m.getArgAsInt32(i));
            }
            else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                msg_string += ofToString(m.getArgAsFloat(i));
            }
            else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
                msg_string += m.getArgAsString(i);
            }
            else{
                msg_string += "unknown";
            }
        }

        cout << "hohans: " << msg_string << "\n";
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
	cout << "Error: " << msg << endl;
}
