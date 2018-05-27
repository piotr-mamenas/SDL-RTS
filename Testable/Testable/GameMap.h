#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <list>
#include <string>

#include "Terrain.h"
#include "Unit.h"
#include "RuleSetManager.h"

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
	int _mapWidth;
	int _mapHeight;
	RuleSetManager* _ruleSet;
public:
	GameMap(int mapWidth, int mapHeight, RuleSetManager* ruleSet);
	GameMap(Terrain* templateTerrain, int mapWidth, int mapHeight, RuleSetManager* ruleSet);
	void getUnits(SDL_Rect* containingBox);
	list<Terrain*> getTerrain();
	void addUnit(Unit* unit);
	void placeTile(Terrain* tile);
	void placeObject(Terrain* object);
	void loadMap(string mapName);
	int getMapWidth();
	int getMapHeight();
};

#endif