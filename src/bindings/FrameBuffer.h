
#include "cinder/gl/gl.h"
#include "cinder/gl/Fbo.h"

class FrameBuffer {

public:
	FrameBuffer();
	FrameBuffer(const int sizex, const int sizey);
	void bind();
	void unbind();
	void draw(int startx, int starty, int sizex, int sizey);
	
private:
	ci::gl::Fbo fbo;
};