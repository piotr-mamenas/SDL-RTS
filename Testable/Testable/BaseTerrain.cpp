#include "BaseTerrain.h"

BaseTerrain::BaseTerrain(unsigned int initialPositionX, unsigned int initialPositionY)
{
	_terrainPositionX = initialPositionX;
	_terrainPositionY = initialPositionY;
}

bool BaseTerrain::isBlocked(int positionX, int positionY, int width, int height)
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

unsigned int BaseTerrain::getId()
{
	return _id;
}

unsigned int BaseTerrain::getPositionX()
{
	return _terrainPositionX;
}

unsigned int BaseTerrain::getPositionY()
{
	return _terrainPositionY;
}