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

	ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);

    ofSetWindowTitle("p x l f k r");
    ofSetFrameRate(60);
    ofSetEscapeQuitsApp(false);
	
	// init the lua state
	lua.init();
	
	// listen to error events
	lua.addListener(this);
	
	// bind the example OF api to the lua state
	lua.bind<ofWrapper>();
	
	// load the pf core
	lua.doScript("scripts/core.lua");
	
	// call the core setup function
	lua.scriptSetup();
}

//--------------------------------------------------------------
void AppCore::update() {
    // call the core update function
	lua.scriptUpdate();
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
