#ifndef GRASSTERRAINTILE_H
#define GRASSTERRAINTILE_H

#include <iostream>
#include <list>

#include "BaseTerrain.h"

using namespace std;

class GrassTerrainTile : public BaseTerrain
{
public:
	GrassTerrainTile(unsigned int initialPositionX, unsigned int initialPositionY);
};

#endif