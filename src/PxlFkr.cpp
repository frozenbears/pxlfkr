#include "cinder/app/AppBasic.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTime.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"

#include "OscListener.h"

#include "LuaBridge.h"

//TODO: pick a non-ridiculous port number
#define PORT 12345

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma mark App

class PxlFkr : public AppBasic {

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

void PxlFkr::keyDown( KeyEvent event )
{
	if( event.getCode() == KeyEvent::KEY_ESCAPE ) {
		setFullScreen( ! isFullScreen() );
	}
}

void PxlFkr::fileDrop( FileDropEvent event )
{
	//we may as well support this event at some point
}

#pragma mark Run Loop

void PxlFkr::setup()
{
	// Todo: enable resize from lua
	setWindowSize(1024, 768);
	
	listener.setup(PORT);
	luaBridge.setup();
}

void PxlFkr::update()
{
	while (listener.hasWaitingMessages()) {
		osc::Message message;
		listener.getNextMessage(&message);
		luaBridge.handleMessage(message);
	}
		
	luaBridge.update();
}

void PxlFkr::draw()
{
	gl::clear( Color( 0, 0, 0 ) );

	//clear the screen, enable alpha
	gl::enableAlphaBlending();
	
	luaBridge.draw();
}

CINDER_APP_BASIC( PxlFkr, RendererGl );
