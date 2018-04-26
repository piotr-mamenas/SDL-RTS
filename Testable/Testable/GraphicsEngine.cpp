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
		//Sprite* unitSprite = unit.getSprite();

		//_drawSprite(_gameScreen, unitSprite, positionX, positionY);
	}
}

void GraphicsEngine::_drawSprite(SDL_Surface* screen, Sprite* sprite, unsigned int positionX, unsigned int positionY)
{
	SDL_Surface* blittedImage = sprite -> getImage();

	SDL_BlitSurface(blittedImage, NULL, screen, NULL);
}