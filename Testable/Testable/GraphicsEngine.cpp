#include "GraphicsEngine.h"
#include "Sprite.h"
#include "BaseUnit.h"
#include "GameAssetManager.h"
#include "GameMap.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>

using namespace std;

GraphicsEngine::GraphicsEngine(SDL_Renderer* gameRenderer, GameAssetManager* assetManager)
{
	_gameAssetManager = assetManager;
	_gameRenderer = gameRenderer;

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) 
	{
		throw std::runtime_error("Could not initialize PNG filetype loading");
	}
}

GraphicsEngine::~GraphicsEngine()
{
	IMG_Quit();
}

void GraphicsEngine::refreshScene(GameMap* gameMap)
{
	SDL_SetRenderDrawColor(_gameRenderer, 0, 0, 0, 250);
	SDL_RenderClear(_gameRenderer);

	_drawGameMap(gameMap);
	
	SDL_RenderPresent(_gameRenderer);
}

void GraphicsEngine::refreshScene(list<BaseUnit*> units, GameMap* gameMap)
{
	SDL_SetRenderDrawColor(_gameRenderer, 0, 0, 0, 255);
	SDL_SetRenderTarget(_gameRenderer, 0);
	SDL_RenderClear(_gameRenderer);

	_drawGameMap(gameMap);
	_drawUnits(units);

	SDL_RenderPresent(_gameRenderer);
}

void GraphicsEngine::_drawUnits(list<BaseUnit*> units)
{
	for (BaseUnit* unit : units)
	{
		bool unitAlive = unit -> isAlive();
		if (unitAlive)
		{
			unsigned int unitId = unit -> getId();
			unsigned int unitPositionX = unit -> getPositionX();
			unsigned int unitPositionY = unit -> getPositionY();

			Sprite* unitSprite = _gameAssetManager -> getUnitSprite(unitId);
			_drawTexture(unitSprite -> getTexture(), unitPositionX, unitPositionY);
		}
	}
	
}

void GraphicsEngine::_drawGameMap(GameMap* gameMap)
{
	list<BaseTerrain*> mapTerrain = gameMap -> getTerrain();
	for (BaseTerrain* terrain : gameMap -> getTerrain())
	{
		unsigned int terrainId = terrain -> getId();
		unsigned int terrainPositionX = terrain->getPositionX();
		unsigned int terrainPositionY = terrain->getPositionY();

		Sprite* terrainSprite = _gameAssetManager-> getTerrainSprite(terrainId);
		_drawTexture(terrainSprite-> getTexture(), terrainPositionX, terrainPositionY);
	}
}

void GraphicsEngine::_drawTexture(SDL_Texture* texture, unsigned int positionX, unsigned int positionY)
{
	SDL_Rect unitPosition;
	unitPosition.x = positionX;
	unitPosition.y = positionY;
	SDL_QueryTexture(texture, NULL, NULL, &unitPosition.w, &unitPosition.h);
	SDL_RenderCopy(_gameRenderer, texture, NULL, &unitPosition);
}