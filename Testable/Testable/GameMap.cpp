#include <SDL.h>

#include "GameMap.h"
#include "GrassTerrainTile.h"

GameMap::GameMap()
{

}

GameMap::GameMap(BaseTerrain* fillTerrain, SDL_Surface* mapSurface)
{
	unsigned int tileMaxHorizontal = (mapSurface->w) / (fillTerrain->getWidth());
	unsigned int tileMaxVertical = (mapSurface->h) / (fillTerrain->getHeight());

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