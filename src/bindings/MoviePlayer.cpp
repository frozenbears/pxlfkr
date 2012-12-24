
#include "MoviePlayer.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

void MoviePlayer::load(const std::string& path) {
	try {
		mMovie = qtime::MovieGl(path);
	} catch (qtime::QuickTimePathInvalidExc &ex) {
		cout << "Invalid movie path: " << path << endl;
	}
}

bool MoviePlayer::isPlayable() {
	if (mMovie) {
		return mMovie.checkPlayable();
	} else {
		return false;
	}
}

int MoviePlayer::getWidth() {
	if (mMovie) {
		return mMovie.getWidth();
	} else {
		return 0;
	}
}

int MoviePlayer::getHeight() {
	if (mMovie) {
		return mMovie.getHeight();
	} else {
		return 0;
	}
}

float MoviePlayer::getAspectRatio() {
	if (mMovie) {
		return mMovie.getAspectRatio();
	} else {
		return 0.0f;
	}
}

float MoviePlayer::getPixelAspectRatio() {
	if (mMovie) {
		return mMovie.getPixelAspectRatio();
	} else {
		return 0.0f;
	}
}

float MoviePlayer::getDuration() {
	if (mMovie) {
		return mMovie.getDuration();
	} else {
		return 0.0f;
	}
}

float MoviePlayer::getFramerate() {
	if (mMovie) {
		return mMovie.getFramerate();
	} else {
		return 0.0f;
	}
}

int MoviePlayer::getNumFrames() {
	if (mMovie) {
		return mMovie.getNumFrames();
	} else {
		return 0;
	}
}

bool MoviePlayer::hasAlpha() {
	if (mMovie) {
		return mMovie.hasAlpha();
	} else {
		return false;
	}
}

bool MoviePlayer::hasVisuals() {
	if (mMovie) {
		return mMovie.hasVisuals();
	} else {
		return false;
	}
}

bool MoviePlayer::hasAudio() {
	if (mMovie) {
		return mMovie.hasAudio();
	} else {
		return false;
	}
}

float MoviePlayer::getCurrentTime() {
	if (mMovie) {
		return mMovie.getCurrentTime();
	} else {
		return 0.0f;
	}
}

void MoviePlayer::seekToTime(float seconds) {
	if (mMovie) {
		mMovie.seekToTime(seconds);
	}
}

void MoviePlayer::seekToFrame(int frame) {
	if (mMovie) {
		mMovie.seekToFrame(frame);
	}
}

void MoviePlayer::seekToStart() {
	if (mMovie) {
		mMovie.seekToStart();
	}
}

void MoviePlayer::seekToEnd() {
	if (mMovie) {
		mMovie.seekToEnd();
	}
}

void MoviePlayer::setActiveSegment(float startTime, float duration) {
	if (mMovie) {
		mMovie.setActiveSegment(startTime, duration);
	}
}

void MoviePlayer::resetActiveSegment() {
	if (mMovie) {
		mMovie.resetActiveSegment();
	}
}

void MoviePlayer::setLoop(bool loop, bool pingpong) {
	if (mMovie) {
		mMovie.setLoop(loop, pingpong); //can tolua++ handle implicit arguments?
	}
}

void MoviePlayer::stepForward() {
	if (mMovie) {
		mMovie.stepForward();
	}
}

void MoviePlayer::stepBackward() {
	if (mMovie) {
		mMovie.stepBackward();
	}
}

void MoviePlayer::setRate(float rate) {
	if (mMovie) {
		mMovie.setRate(rate);
	}
}

void MoviePlayer::setVolume(float volume) {
	if (mMovie) {
		mMovie.setVolume(volume);
	}
}

float MoviePlayer::getVolume() {
	if (mMovie) {
		return mMovie.getVolume();
	} else {
		return 0.0f;
	}
}

bool MoviePlayer::isPlaying() {
	if (mMovie) {
		return mMovie.isPlaying();
	} else {
		return false;
	}
}

bool MoviePlayer::isDone() {
	if (mMovie) {
		return mMovie.isDone();
	} else {
		return false;
	}
}

void MoviePlayer::play() {
	if (mMovie) {
		mMovie.play();
	}
}

void MoviePlayer::stop() {
	if (mMovie) {
		mMovie.stop();
	}
}

void MoviePlayer::draw(int x, int y, int sizex, int sizey) {
	if (mMovie) {
		if (mMovie.getTexture() != NULL) {
			gl::draw(mMovie.getTexture(), Rectf(x, y, x+sizex, sizey+y));
		}
	}
}