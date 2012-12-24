
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTime.h"

class MoviePlayer {
	
public:	
	void load(const std::string& path);
	
	bool isPlayable();
	int getWidth();
	int getHeight();
	
	float getAspectRatio();
	float getPixelAspectRatio();
	float getDuration();
	float getFramerate();
	int getNumFrames();
	
	bool hasAlpha();
	bool hasVisuals();
	bool hasAudio();
	
	float getCurrentTime();
	void seekToTime(float seconds);
	void seekToFrame(int frame);
	void seekToStart();
	void seekToEnd();
	
	void setActiveSegment(float startTime, float duration);
	void resetActiveSegment();
	void setLoop(bool loop, bool pingpong);
	void stepForward();
	void stepBackward();
	
	void setRate(float rate);
	void setVolume(float volume);
	float getVolume();
	
	bool isPlaying();
	bool isDone();
	
	void play();
	void stop();
	
	void draw(int x, int y, int sizex, int sizey);
	
private:
	ci::qtime::MovieGl mMovie;
};