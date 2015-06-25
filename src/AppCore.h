
#pragma once

#include "ofMain.h"

#include "ofxLua.h"
#include "ofxOsc.h"
#include "ofxLuaBindings.h"	// the OF api -> lua binding

class AppCore : ofxLuaListener {

	public:

		// main
		void setup();
		void update();
		void draw();
        void exit();
		
		// input
		void keyPressed(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
		// ofxLua error callback
		void errorReceived(string& msg);
		
		ofxLua lua;
        ofxOscReceiver oscReceiver;
};
