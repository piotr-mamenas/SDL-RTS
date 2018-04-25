#include "GraphicsEngine.h"
#include "Sprite.h"
#include "BaseUnit.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

GraphicsEngine::GraphicsEngine(SDL_Window* gameWindow, SDL_Surface* gameScreen)
{
	_gameWindow = gameWindow;
	_gameScreen = gameScreen;

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) 
	{
		throw std::runtime_error("Could not initialize PNG filetype loading");
	}
}

void GraphicsEngine::drawScene(list<BaseUnit> units)
{
	_drawUnits(units);
}

void GraphicsEngine::addToScene(Sprite* sprite)
{
	_unitImages.push_back(sprite);
}

void GraphicsEngine::_drawUnits(list<BaseUnit> units)
{
	for (BaseUnit unit : units)
	{
		unsigned int positionX = unit.getPositionX();
		unsigned int positionY = unit.getPositionY();
		Sprite* unitSprite = unit.getSprite();

		_drawSprite(_gameScreen, unitSprite, positionX, positionY);
	}
}

void GraphicsEngine::_drawSprite(SDL_Surface* screen, Sprite* sprite, unsigned int positionX, unsigned int positionY)
{
	SDL_Surface* blittedImage = sprite -> getImage();

	SDL_BlitSurface(blittedImage, NULL, screen, NULL);
}

SDL_Surface* GraphicsEngine::_loadSurface(string path)
{
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, _gameScreen -> format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}