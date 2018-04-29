#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <iostream>
#include <SDL.h>

class GameTimer
{
private:
	Uint32 _startTicks;
	Uint32 _pausedTicks;

	bool _isPaused;
	bool _isStarted;
public:
	GameTimer();
	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();
};

#endif