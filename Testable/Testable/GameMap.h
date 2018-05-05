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
public:
	GameMap();
	GameMap(BaseTerrain* fillTerrain, SDL_Surface* mapSurface);
	list<BaseTerrain*> getTerrain();
};

#endif