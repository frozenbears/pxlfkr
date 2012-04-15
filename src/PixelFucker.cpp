#include "cinder/app/AppBasic.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTime.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"

#include "OscListener.h"

#include "LuaBridge.h"

#define PORT 12345

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma mark App

class PixelFucker : public AppBasic {

public:

	void keyDown( KeyEvent event );
	void fileDrop( FileDropEvent event );
	
	void setup();
	void update();
	void draw();
	
	osc::Listener listener;
    LuaBridge luaBridge;
	
};

#pragma mark Events

void PixelFucker::keyDown( KeyEvent event )
{
	//Todo: change to ESC
	if( event.getCode() == KeyEvent::KEY_ESCAPE ) {
		setFullScreen( ! isFullScreen() );
	}
}

void PixelFucker::fileDrop( FileDropEvent event )
{
	//we may as well support this event at some point
}

#pragma mark Run Loop

void PixelFucker::setup()
{
	// Todo: enable resize from lua
	setWindowSize(1024, 768);
	
	listener.setup(PORT);
	luaBridge.setup();
}

void PixelFucker::update()
{
	while (listener.hasWaitingMessages()) {
		osc::Message message;
		listener.getNextMessage(&message);
		luaBridge.handleMessage(message);
	}
		
	luaBridge.update();
}

void PixelFucker::draw()
{
	
	gl::clear( Color( 0, 0, 0 ) );

	//clear the screen, enable alpha
	gl::enableAlphaBlending();
	
	luaBridge.draw();
}

CINDER_APP_BASIC( PixelFucker, RendererGl );
