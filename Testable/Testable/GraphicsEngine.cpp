#include "GraphicsEngine.h"
#include "Sprite.h"
#include "BaseUnit.h"
#include "GameAssetManager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>

using namespace std;

GraphicsEngine::GraphicsEngine(SDL_Window* gameWindow, SDL_Surface* gameScreen, GameAssetManager* assetManager)
{
	_gameWindow = gameWindow;
	_gameScreen = gameScreen;
	_gameAssetManager = assetManager;

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) 
	{
		throw std::runtime_error("Could not initialize PNG filetype loading");
	}
}

void GraphicsEngine::drawScene(list<BaseUnit*> units)
{
	_drawUnits(units);
}

void GraphicsEngine::addToScene(Sprite* sprite)
{
	_unitImages.push_back(sprite);
}

void GraphicsEngine::_drawUnits(list<BaseUnit*> units)
{
	for (BaseUnit* unit : units)
	{
		if (unit -> isAlive())
		{
			unsigned int unitId = unit -> getId();
			unsigned int unitPositionX = unit -> getPositionX();
			unsigned int unitPositionY = unit -> getPositionY();

			SDL_Surface* unitImage = _gameAssetManager -> getUnitImage(unitId);
			_drawImage(_gameScreen, unitImage, unitPositionX, unitPositionY);
		}
	}
	SDL_UpdateWindowSurface(_gameWindow);
}

void GraphicsEngine::_drawImage(SDL_Surface* screen, SDL_Surface* image, unsigned int positionX, unsigned int positionY)
{
	SDL_Rect unitPosition;
	unitPosition.x = positionX;
	unitPosition.y = positionY;

	SDL_BlitSurface(image, NULL, screen, &unitPosition);
}