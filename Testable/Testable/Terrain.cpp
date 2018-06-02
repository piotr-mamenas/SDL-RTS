#include "Terrain.h"
#include "GameObject.h"

#include <nlohmann\json.hpp>

using json = nlohmann::json;

Terrain::Terrain(int initialPositionX, int initialPositionY, Terrain* terrainTemplate) 
	: GameObject(initialPositionX, initialPositionY)
{
	_id = terrainTemplate->getId();
	_width = terrainTemplate->getWidth();
	_height = terrainTemplate->getHeight();
}

Terrain::Terrain(json terrainJson)
	: GameObject(terrainJson)
{

}

bool Terrain::isBlocked(int positionX, int positionY, int width, int height)
{
	if (_isBlocking)
	{
		return true;
	}

	if (positionX + width < _blockingXStart)
	{
		return false;
	}

	if (positionX > _blockingXEnd)
	{
		return false;
	}

	if (positionY + height < _blockingYStart)
	{
		return false;
	}

	if (positionY > _blockingYEnd)
	{
		return false;
	}

	return true;
}

void Terrain::deserializeFrom(json json)
{
	_id = json.at("id").get<int>();
	_spriteId = json.at("spriteId").get<int>();
	_width = json.at("width").get<int>();
	_height = json.at("height").get<int>();
}