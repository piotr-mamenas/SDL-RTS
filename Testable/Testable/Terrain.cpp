#include "Terrain.h"

#include <nlohmann\json.hpp>

using json = nlohmann::json;

Terrain::Terrain(int terrainId, int initialPositionX, int initialPositionY)
	: GameObject(terrainId, initialPositionX, initialPositionY)
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
	_width = json.at("width");
	_height = json.at("height");
}