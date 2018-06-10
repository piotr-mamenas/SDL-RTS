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

const std::string MAPFILE_FORMAT = "json";

using json = nlohmann::json;

GameMap::GameMap(int mapWidth, int mapHeight, std::shared_ptr<RuleSetManager> ruleSet)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
	_ruleSet = ruleSet;
}

GameMap::GameMap(std::shared_ptr<Terrain> templateTerrain, int mapWidth, int mapHeight, std::shared_ptr<RuleSetManager> ruleSet)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
	_ruleSet = ruleSet;

	if (mapWidth % MAX_TILE_SIZE != 0)
	{
		throw new std::logic_error("Map Size X not divisable by allowed Tile Size X");
	}

	if (mapHeight % MAX_TILE_SIZE != 0)
	{
		throw new std::logic_error("Map Size Y not divisable by allowed Tile Size Y");
	}

	_fillMapWithTerrain(templateTerrain);
}

void GameMap::_fillMapWithTerrain(std::shared_ptr<Terrain> templateTerrain)
{
	int tileMaxHorizontal = (_mapWidth) / (templateTerrain->getWidth());
	int tileMaxVertical = (_mapHeight) / (templateTerrain->getHeight());

	for (int cntX = 0; cntX < tileMaxHorizontal; cntX++)
	{
		for (int cntY = 0; cntY < tileMaxVertical; cntY++)
		{
			std::unique_ptr<Terrain> terrainTile = std::make_unique<Terrain>(new Terrain(cntX*templateTerrain->getWidth(), cntY*templateTerrain->getHeight(), _ruleSet->getTerrainTemplate(1)));
			_mapTerrain.push_back(terrainTile);
		}
	}
}

std::vector<std::unique_ptr<Terrain>> GameMap::getTerrain()
{
	return _mapTerrain;
}

void GameMap::getUnits(std::unique_ptr<SDL_Rect> containingBox)
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

void GameMap::loadMap(std::string mapName)
{
	std::string mapFilename = mapName + std::string(".") + MAPFILE_FORMAT;
	std::cout << mapFilename << std::endl;
	std::ifstream mapFile(mapFilename);

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
				std::shared_ptr<Terrain> terrainTemplate = _ruleSet->getTerrainTemplate(terrainId);
				_mapTerrain.push_back(std::make_unique<Terrain>(new Terrain(positionX, positionY, terrainTemplate)));
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