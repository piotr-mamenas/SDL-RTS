#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <list>
#include <string>

#include "BaseTerrain.h"
#include "BaseUnit.h"

#include <SDL.h>

using namespace std;

class GameMap
{
private:
	void _fillMapWithTerrain(BaseTerrain* terrain);
	list<BaseTerrain*> _mapTerrain;
	list<BaseTerrain*> _mapObjects;
	list<BaseUnit*> _preplacedMapUnits;
	list<SDL_Rect*> _blockedArea;
	unsigned int _mapWidth;
	unsigned int _mapHeight;
public:
	GameMap(unsigned int mapWidth, unsigned int mapHeight);
	GameMap(BaseTerrain* templateTerrain, unsigned int mapWidth, unsigned int mapHeight);
	void getUnits(SDL_Rect* containingBox);
	list<BaseTerrain*> getTerrain();
	void addUnit(BaseUnit* unit);
	void placeTile(BaseTerrain* tile);
	void placeObject(BaseTerrain* object);
	void loadMap(string mapName);
	unsigned int getMapWidth();
	unsigned int getMapHeight();
};

#endif