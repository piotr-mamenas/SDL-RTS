#include "BaseUnit.h"
#include "GameObject.h"

#include <iostream>

BaseUnit::BaseUnit(unsigned int initialPositionX, unsigned int initialPositionY) 
	: GameObject(initialPositionX, initialPositionY)
{
	_isAlive = true;
}

void BaseUnit::handleEvent(unsigned int clickPositionX, unsigned int clickPositionY, int eventType)
{
	if (_isAlive) 
	{
		bool mouseInside = true;

		if (clickPositionX < _positionX ||
			clickPositionX > _positionX + _width ||
			clickPositionY < _positionY ||
			clickPositionY > _positionY + _height)
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