#include "GameTimer.h"
#include <SDL.h>

GameTimer::GameTimer()
{
	_startTicks = 0;
	_pausedTicks = 0;

	_isPaused = false;
	_isStarted = false;
}

void GameTimer::start()
{
	_isStarted = true;
	_isPaused = false;

	_startTicks = SDL_GetTicks();
	_pausedTicks = 0;
}

void GameTimer::stop()
{
	_isStarted = false;
	_isPaused = false;

	_startTicks = 0;
	_pausedTicks = 0;
}

void GameTimer::pause()
{
	if (_isStarted && !_isPaused)
	{
		_isPaused = true;
		_pausedTicks = SDL_GetTicks() - _startTicks;
		_startTicks = 0;
	}
}

void GameTimer::unpause()
{
	if (_isStarted && _isPaused)
	{
		_isPaused = false;
		_startTicks = SDL_GetTicks() - _pausedTicks;

		_pausedTicks = 0;
	}
}

Uint32 GameTimer::getTicks()
{
	Uint32 time = 0;

	if (_isStarted)
	{
		if (_isPaused)
		{
			time = _pausedTicks;
		}
		else 
		{
			time = SDL_GetTicks() - _startTicks;
		}
	}
	return time;
}

bool GameTimer::isStarted()
{
	return _isStarted;
}

bool GameTimer::isPaused()
{
	return _isPaused && _isStarted;
}