
#include "Drawing.h"

#include "cinder/gl/gl.h"
#include <vector>

using namespace ci;

void color(float r, float g, float b, float a) {
	gl::color(r, g, b, a);
}


void line(int startx, int starty, int endx, int endy) {
	gl::drawLine(Vec2f(startx, starty), Vec2f(endx, endy));
}

void solidCircle(int centerx, int centery, int radius, int numsegments) {
	gl::drawSolidCircle(Vec2f(centerx, centery), radius, numsegments); 
}