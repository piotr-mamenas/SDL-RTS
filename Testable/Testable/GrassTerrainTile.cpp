#include "GrassTerrainTile.h"
#include "BaseTerrain.h"

#define GRASSTILE_WIDTH 90;
#define GRASSTILE_HEIGHT 90;
#define GRASSTILE_ID 2501

GrassTerrainTile::GrassTerrainTile(unsigned int initialPositionX, unsigned int initialPositionY)
	: BaseTerrain(initialPositionX, initialPositionY)
{
	_width = GRASSTILE_WIDTH;
	_height = GRASSTILE_HEIGHT;
	_id = GRASSTILE_ID;
}