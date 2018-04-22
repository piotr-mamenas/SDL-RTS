#include "GraphicsEngine.h"
#include "Sprite.h"

#include <SDL.h>

using namespace std;

GraphicsEngine::GraphicsEngine(SDL_Window* gameWindow, SDL_Surface* gameScreen)
{
	_gameWindow = gameWindow;
	_gameScreen = gameScreen;
}

void GraphicsEngine::drawScene()
{
	_drawUnits();
}

void GraphicsEngine::_drawUnits()
{
	for (Sprite* unit : _unitImages) 
	{
		_drawSprite(_gameScreen, unit);
	}
}

void GraphicsEngine::_drawSprite(SDL_Surface* screen, Sprite* sprite)
{
	SDL_Surface* blittedImage = sprite->_getImage();

	SDL_BlitSurface(blittedImage, NULL, screen, NULL);
}