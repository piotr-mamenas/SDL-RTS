#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <list>

#include "BaseTerrain.h"

using namespace std;

class GameMap
{
private:
	list<BaseTerrain*> _mapTerrain;
	unsigned int _mapWidth;
	unsigned int _mapHeight;
public:
	GameMap(unsigned int mapWidth, unsigned int mapHeight);
	GameMap(BaseTerrain* fillTerrain, unsigned int mapWidth, unsigned int mapHeight);
	list<BaseTerrain*> getTerrain();
};

#endif