
#include "FrameBuffer.h"
#include "cinder/Cinder.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

FrameBuffer::FrameBuffer(){};

FrameBuffer::FrameBuffer(const int sizex, const int sizey) {
	fbo = gl::Fbo(sizex, sizey);
}

void FrameBuffer::bind() {
	fbo.bindFramebuffer();
	gl::clear(Color(0,0,0));
	gl::setViewport(fbo.getBounds());
}

void FrameBuffer::unbind() {
	fbo.unbindFramebuffer();
	gl::setViewport(app::getWindowBounds());
}

void FrameBuffer::draw(int startx, int starty, int sizex, int sizey) {
	fbo.bindTexture();
	//swap the y coordinates and draw with absolute x/y offsets
	//TODO abstract this at a higher level?
	gl::draw(fbo.getTexture(0), Rectf(startx, sizey+starty, startx+sizex, starty));
}
	