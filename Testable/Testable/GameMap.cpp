#include <SDL.h>

#include "GameMap.h"
#include "GrassTerrainTile.h"

GameMap::GameMap(unsigned int mapWidth, unsigned int mapHeight)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
}

GameMap::GameMap(BaseTerrain* fillTerrain, unsigned int mapWidth, unsigned int mapHeight)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;

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