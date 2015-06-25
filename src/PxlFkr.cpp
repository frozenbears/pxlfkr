
#include "PxlFkr.h"

//--------------------------------------------------------------
void PxlFkr::setup() {
	core.setup();
}

//--------------------------------------------------------------
void PxlFkr::update() {
	core.update();
}

//--------------------------------------------------------------
void PxlFkr::draw() {
	core.draw();
}

//--------------------------------------------------------------
void PxlFkr::exit() {
	core.exit();
}

//--------------------------------------------------------------
void PxlFkr::keyPressed(int key) {
	core.keyPressed(key);
}

//--------------------------------------------------------------
void PxlFkr::mouseMoved(int x, int y) {
	core.mouseMoved(x, y);
}

//--------------------------------------------------------------
void PxlFkr::mouseDragged(int x, int y, int button) {
	core.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void PxlFkr::mousePressed(int x, int y, int button) {
	core.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void PxlFkr::mouseReleased(int x, int y, int button) {
	core.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void PxlFkr::windowResized(int w, int h) {}
