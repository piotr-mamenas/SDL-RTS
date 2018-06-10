#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <string>
#include <memory>

#include "Terrain.h"
#include "Unit.h"
#include "RuleSetManager.h"

#include <SDL.h>

class GameMap
{
private:
	void _fillMapWithTerrain(std::shared_ptr<Terrain> terrain);
	std::vector<std::unique_ptr<Terrain>> _mapTerrain;
	std::vector<std::unique_ptr<Terrain>> _mapObjects;
	std::vector<std::unique_ptr<Unit>> _preplacedMapUnits;
	std::vector<std::unique_ptr<SDL_Rect>> _blockedArea;
	int _mapWidth;
	int _mapHeight;
	std::shared_ptr<RuleSetManager> _ruleSet;
public:
	GameMap(int mapWidth, int mapHeight, std::shared_ptr<RuleSetManager> ruleSet);
	GameMap(std::shared_ptr<Terrain> templateTerrain, int mapWidth, int mapHeight, std::shared_ptr<RuleSetManager> ruleSet);
	void getUnits(std::unique_ptr<SDL_Rect> containingBox);
	std::vector<std::unique_ptr<Terrain>> getTerrain();
	void loadMap(std::string mapName);
	int getMapWidth();
	int getMapHeight();
};

#endif