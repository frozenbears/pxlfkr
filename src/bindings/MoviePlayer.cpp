
#include "MoviePlayer.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

void MoviePlayer::load(const std::string& path) {
	mMovie = qtime::MovieGl(path);
}

bool MoviePlayer::isPlayable() {
	return mMovie.checkPlayable(); //naming?
}

int MoviePlayer::getWidth() {
	return mMovie.getWidth();
}

int MoviePlayer::getHeight() {
	return mMovie.getHeight();
}

float MoviePlayer::getAspectRatio() {
	return mMovie.getAspectRatio();
}

float MoviePlayer::getPixelAspectRatio() {
	return mMovie.getPixelAspectRatio();
}

float MoviePlayer::getDuration() {
	return mMovie.getDuration();
}

float MoviePlayer::getFramerate() {
	return mMovie.getFramerate();
}

int MoviePlayer::getNumFrames() {
	return mMovie.getNumFrames();
}

bool MoviePlayer::hasAlpha() {
	return mMovie.hasAlpha();
}

bool MoviePlayer::hasVisuals() {
	return mMovie.hasVisuals();
}

bool MoviePlayer::hasAudio() {
	return mMovie.hasAudio();
}

float MoviePlayer::getCurrentTime() {
	return mMovie.getCurrentTime();
}

void MoviePlayer::seekToTime(float seconds) {
	mMovie.seekToTime(seconds);
}

void MoviePlayer::seekToFrame(int frame) {
	mMovie.seekToFrame(frame);
}

void MoviePlayer::seekToStart() {
	mMovie.seekToStart();
}

void MoviePlayer::seekToEnd() {
	mMovie.seekToEnd();
}

void MoviePlayer::setActiveSegment(float startTime, float duration) {
	mMovie.setActiveSegment(startTime, duration);
}

void MoviePlayer::resetActiveSegment() {
	mMovie.resetActiveSegment();
}

void MoviePlayer::setLoop(bool loop, bool pingpong) {
	mMovie.setLoop(loop, pingpong); //can tolua++ handle implicit arguments?
}

void MoviePlayer::stepForward() {
	mMovie.stepForward();
}

void MoviePlayer::stepBackward() {
	mMovie.stepBackward();
}

void MoviePlayer::setRate(float rate) {
	mMovie.setRate(rate);
}

void MoviePlayer::setVolume(float volume) {
	mMovie.setVolume(volume);
}

float MoviePlayer::getVolume() {
	return mMovie.getVolume();
}

bool MoviePlayer::isPlaying() {
	return mMovie.isPlaying();
}

bool MoviePlayer::isDone() {
	return mMovie.isDone();
}

void MoviePlayer::play() {
	mMovie.play();
}

void MoviePlayer::stop() {
	mMovie.stop();
}

void MoviePlayer::draw(int x, int y, int sizex, int sizey) {
	if (mMovie.getTexture()) {
		gl::draw(mMovie.getTexture(), Rectf(x, y, x+sizex, sizey+y));
	}
}