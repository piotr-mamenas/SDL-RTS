#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SDL.h>
#include <iostream>
#include <list>

#include "GraphicsEngine.h"

using namespace std;

class GameContext
{
private:
	SDL_Window* gameWindow = NULL;
	SDL_Surface* mainSurface = NULL;
	int _screenWidth;
	int _screenHeight;
	int _windowStatus;
	list<BaseUnit> _units;

	void _updateGraphics(GraphicsEngine* graphicsEngine);
public:
	GameContext(int screenWidth, int screenHeight, bool isMinimized);
	bool init(bool isMinized);
	void close();
};

#endif