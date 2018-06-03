#include <iostream>
#include <fstream>
#include <exception>

#include "GameMap.h"
#include "Terrain.h"
#include "Unit.h"
#include "RuleSetManager.h"

#include <nlohmann/json.hpp>
#include <SDL.h>

#define MAX_TILE_SIZE 90

const string MAPFILE_FORMAT = "json";

using namespace std;
using json = nlohmann::json;

GameMap::GameMap(int mapWidth, int mapHeight, RuleSetManager* ruleSet)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
	_ruleSet = ruleSet;
}

GameMap::GameMap(Terrain* templateTerrain, int mapWidth, int mapHeight, RuleSetManager* ruleSet)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
	_ruleSet = ruleSet;

	if (mapWidth % MAX_TILE_SIZE != 0)
	{
		throw new logic_error("Map Size X not divisable by allowed Tile Size X");
	}

	if (mapHeight % MAX_TILE_SIZE != 0)
	{
		throw new logic_error("Map Size Y not divisable by allowed Tile Size Y");
	}

	_fillMapWithTerrain(templateTerrain);
}

void GameMap::_fillMapWithTerrain(Terrain* templateTerrain)
{
	int tileMaxHorizontal = (_mapWidth) / (templateTerrain->getWidth());
	int tileMaxVertical = (_mapHeight) / (templateTerrain->getHeight());

	for (int cntX = 0; cntX < tileMaxHorizontal; cntX++)
	{
		for (int cntY = 0; cntY < tileMaxVertical; cntY++)
		{
			//TODO: Naprawic

			Terrain* terrainTile = new Terrain(cntX*templateTerrain->getWidth(), cntY*templateTerrain->getHeight(), _ruleSet->getTerrainTemplate(1));
			_mapTerrain.push_back(terrainTile);
		}
	}
}

list<Terrain*> GameMap::getTerrain()
{
	return _mapTerrain;
}

void GameMap::getUnits(SDL_Rect* containingBox)
{

}

void GameMap::addUnit(Unit* unit)
{

}

void GameMap::placeTile(Terrain* tile)
{
	
}

void GameMap::placeObject(Terrain* object)
{

}

int GameMap::getMapWidth()
{
	return _mapWidth;
}

int GameMap::getMapHeight()
{
	return _mapHeight;
}

void GameMap::loadMap(string mapName)
{
	string mapFilename = mapName + string(".") + MAPFILE_FORMAT;
	cout << mapFilename << endl;
	ifstream mapFile(mapFilename);

	try
	{
		json map;
		mapFile >> map;

		for (auto& element : map)
		{
			for (auto& tile : element.at("tiles"))
			{
				int terrainId = tile.at("terrainId").get<int>();
				int positionX = tile.at("positionX").get<int>();
				int positionY = tile.at("positionY").get<int>();
				Terrain* terrainTemplate = _ruleSet->getTerrainTemplate(terrainId);
				_mapTerrain.push_back(new Terrain(positionX, positionY, terrainTemplate));
			}
		}
	}
	catch (json::parse_error& e)
	{
		// output exception information
		std::cout << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << std::endl;
	}
}