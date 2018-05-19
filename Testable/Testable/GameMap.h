#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <list>
#include <string>

#include "Terrain.h"
#include "Unit.h"

#include <SDL.h>

using namespace std;

class GameMap
{
private:
	void _fillMapWithTerrain(Terrain* terrain);
	list<Terrain*> _mapTerrain;
	list<Terrain*> _mapObjects;
	list<Unit*> _preplacedMapUnits;
	list<SDL_Rect*> _blockedArea;
	unsigned int _mapWidth;
	unsigned int _mapHeight;
public:
	GameMap(unsigned int mapWidth, unsigned int mapHeight);
	GameMap(Terrain* templateTerrain, unsigned int mapWidth, unsigned int mapHeight);
	void getUnits(SDL_Rect* containingBox);
	list<Terrain*> getTerrain();
	void addUnit(Unit* unit);
	void placeTile(Terrain* tile);
	void placeObject(Terrain* object);
	void loadMap(string mapName);
	unsigned int getMapWidth();
	unsigned int getMapHeight();
};

#endif