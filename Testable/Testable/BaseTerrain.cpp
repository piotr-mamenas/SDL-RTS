#include "BaseTerrain.h"

BaseTerrain::BaseTerrain(unsigned int initialPositionX, unsigned int initialPositionY)
	: GameObject(initialPositionX, initialPositionY)
{
}

bool BaseTerrain::isBlocked(unsigned int positionX, unsigned int positionY, unsigned int width, unsigned int height)
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

unsigned int BaseTerrain::getWidth()
{
	return _width;
}

unsigned int BaseTerrain::getHeight()
{
	return _height;
}