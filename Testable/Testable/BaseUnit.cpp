#include "BaseUnit.h"

#include <iostream>

BaseUnit::BaseUnit(unsigned int initialPositionX, unsigned int initialPositionY)
{
	_mapPositionX = initialPositionX;
	_mapPositionY = initialPositionY;
	_isAlive = true;
}

unsigned int BaseUnit::getPositionX()
{
	return _mapPositionX;
}

unsigned int BaseUnit::getPositionY()
{
	return _mapPositionY;
}

unsigned int BaseUnit::getId()
{
	return _id;
}

void BaseUnit::handleEvent(int clickPositionX, int clickPositionY, int eventType)
{
	if (_isAlive) 
	{
		bool mouseInside = true;

		if (clickPositionX < _mapPositionX ||
			clickPositionX > _mapPositionX + _unitWidth ||
			clickPositionY < _mapPositionY ||
			clickPositionY > _mapPositionY + _unitHeight)
		{
			mouseInside = false;
		}

		if (mouseInside)
		{
			switch (eventType)
			{
			case SDL_MOUSEBUTTONDOWN:
				printf("Mouse Down Unit: %d\n", _id);
				_currentLife = _currentLife - 5;
				if (_currentLife <= 0)
				{
					_isAlive = false;
				}

				break;
			case SDL_MOUSEBUTTONUP:
				printf("Mouse Up Unit: %d\n", _id);
				break;
			}
		}
	}
}

bool BaseUnit::isAlive()
{
	return _isAlive;
}