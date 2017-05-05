
#include "AppCore.h"
#include "OscMessageTable.h"
#include "lfs.h"

void AppCore::setup() {

    oscReceiver.setup(12345);

    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_WARNING);

    ofSetWindowTitle("p x l f k r");
    ofSetFrameRate(60);
    ofSetEscapeQuitsApp(false);

    // init the lua state
    lua.init();
    lua.addListener(this);

    // init lfs
    luaopen_lfs(lua);

    // bind the OF api
    lua.bind<ofxLuaBindings>();
    // load the pf core
    lua.doScript("scripts/core.lua");
    // set it up
    lua.scriptSetup();
}

void AppCore::update() {
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

void AppCore::draw() {
    lua.scriptDraw();
}

void AppCore::exit() {
    lua.scriptExit();

    // clean up
    lua.clear();
}

void AppCore::toggleFullscreen() {
    fullscreen = !fullscreen;
    ofSetFullscreen(fullscreen);
    float aspectRatio = ofGetWidth() / ofGetHeight();
    gluOrtho2D(0.0, ofGetWidth() * aspectRatio, 0.0, ofGetHeight());
}

//--------------------------------------------------------------
void AppCore::keyPressed(int key) {
    switch(key) {
        case OF_KEY_ESC:
            toggleFullscreen();
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
