#include "cinder/app/AppBasic.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTime.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"

#include "OscListener.h"

#include "AviatorBridge.h"

#include "TestClass.h"

#define PORT 12345

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma mark App

class Aviator : public AppBasic {

public:

	void keyDown( KeyEvent event );
	void fileDrop( FileDropEvent event );
	
	void setup();
	void update();
	void draw();
	
	osc::Listener listener;
	AviatorBridge av;
};

#pragma mark Events

void Aviator::keyDown( KeyEvent event )
{
	//Todo: change to ESC
	if( event.getCode() == KeyEvent::KEY_ESCAPE ) {
		setFullScreen( ! isFullScreen() );
	}
}

void Aviator::fileDrop( FileDropEvent event )
{
	//we may as well support this event at some point
}

#pragma mark Run Loop

void Aviator::setup()
{
	// Todo: enable resize from lua
	setWindowSize(1024, 768);
	
	listener.setup(PORT);
	av.setup();
}

void Aviator::update()
{
	while (listener.hasWaitingMessages()) {
		osc::Message message;
		listener.getNextMessage(&message);
		av.handleMessage(message);
	}
		
	av.update();
	
}

void Aviator::draw()
{
	//clear the screen, enable alpha
	gl::clear( Color( 0, 0, 0 ) );
	gl::enableAlphaBlending();
	
	av.draw();
}

//DO IT
CINDER_APP_BASIC( Aviator, RendererGl );
