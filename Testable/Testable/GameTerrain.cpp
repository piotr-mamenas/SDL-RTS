#include "GameTerrain.h"

GameTerrain::GameTerrain()
{

}

bool GameTerrain::isBlocked(int positionX, int positionY, int width, int height) 
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

Sprite* GameTerrain::getSprite()
{
	return _terrainSprite;
}