#include <SDL.h>

#include <exception>

#include "GameMap.h"
#include "GrassTerrainTile.h"

#define MAX_TILE_SIZE 90

using namespace std;

GameMap::GameMap(unsigned int mapWidth, unsigned int mapHeight)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
}

GameMap::GameMap(BaseTerrain* fillTerrain, unsigned int mapWidth, unsigned int mapHeight)
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

	unsigned int tileMaxHorizontal = (mapWidth) / (fillTerrain->getWidth());
	unsigned int tileMaxVertical = (mapHeight) / (fillTerrain->getHeight());

	for (unsigned int cntX = 0; cntX < tileMaxHorizontal; cntX++)
	{
		for (unsigned int cntY = 0; cntY < tileMaxHorizontal; cntY++)
		{
			BaseTerrain* terrainTile = new GrassTerrainTile(cntX*fillTerrain->getWidth(), cntY*fillTerrain->getHeight());
			_mapTerrain.push_back(terrainTile);
		}
	}
}

list<BaseTerrain*> GameMap::getTerrain()
{
	return _mapTerrain;
}

unsigned int GameMap::getMapWidth()
{
	return _mapWidth;
}

unsigned int GameMap::getMapHeight()
{
	return _mapHeight;
}