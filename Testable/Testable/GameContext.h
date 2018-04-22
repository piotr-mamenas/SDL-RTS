#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SDL.h>

class GameContext
{
private:
	SDL_Window* gameWindow = NULL;
	SDL_Surface* mainSurface = NULL;

public:
	bool Init();
	void Close();
	bool SetBrush();
};

#endif