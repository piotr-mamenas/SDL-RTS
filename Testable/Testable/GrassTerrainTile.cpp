#include "GrassTerrainTile.h"
#include "BaseTerrain.h"

#define GRASSTILE_WIDTH 90;
#define GRASSTILE_HEIGHT 90;
#define GRASSTILE_ID 1

GrassTerrainTile::GrassTerrainTile(unsigned int initialPositionX, unsigned int initialPositionY)
	: BaseTerrain(initialPositionX, initialPositionY)
{
	_terrainWidth = GRASSTILE_WIDTH;
	_terrainHeight = GRASSTILE_HEIGHT;
	_id = GRASSTILE_ID;
}