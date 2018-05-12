#include <SDL.h>

#include <exception>

#include "GameMap.h"
#include "GrassTerrainTile.h"
#include "BaseUnit.h"

#define MAX_TILE_SIZE 90

using namespace std;

GameMap::GameMap(unsigned int mapWidth, unsigned int mapHeight)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
}

GameMap::GameMap(BaseTerrain* templateTerrain, unsigned int mapWidth, unsigned int mapHeight)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;

	if (mapWidth % MAX_TILE_SIZE != 0)
	{
		throw new logic_error("Map Size X not divisable by allowed Tile Size X");
	}

	if (mapHeight % MAX_TILE_SIZE != 0)
	{
		throw new logic_error("Map Size Y not divisable by allowed Tile Size Y");
	}

	_fillMapWithTerrain(templateTerrain);
}

void GameMap::_fillMapWithTerrain(BaseTerrain* templateTerrain)
{
	unsigned int tileMaxHorizontal = (_mapWidth) / (templateTerrain->getWidth());
	unsigned int tileMaxVertical = (_mapHeight) / (templateTerrain->getHeight());

	for (unsigned int cntX = 0; cntX < tileMaxHorizontal; cntX++)
	{
		for (unsigned int cntY = 0; cntY < tileMaxVertical; cntY++)
		{
			BaseTerrain* terrainTile = new GrassTerrainTile(cntX*templateTerrain->getWidth(), cntY*templateTerrain->getHeight());
			_mapTerrain.push_back(terrainTile);
		}
	}
}

list<BaseTerrain*> GameMap::getTerrain()
{
	return _mapTerrain;
}

void GameMap::getUnits(SDL_Rect* containingBox)
{

}

void GameMap::addUnit(BaseUnit* unit)
{

}

void GameMap::placeTile(BaseTerrain* tile)
{
	
}

void GameMap::placeObject(BaseTerrain* object)
{

}

unsigned int GameMap::getMapWidth()
{
	return _mapWidth;
}

unsigned int GameMap::getMapHeight()
{
	return _mapHeight;
}