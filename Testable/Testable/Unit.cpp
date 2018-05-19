#include "Unit.h"
#include "GameObject.h"

#include <iostream>
#include <string>

Unit::Unit(int unitId, int initialPositionX, int initialPositionY) 
	: GameObject(unitId, initialPositionX, initialPositionY)
{
	_unitId = unitId;
	_isAlive = true;
}

void Unit::handleEvent(int clickPositionX, int clickPositionY, int eventType)
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
				_currentLife = _currentLife - 5;
				if (_currentLife <= 0)
				{
					_isAlive = false;
				}

				break;
			case SDL_MOUSEBUTTONUP:
				break;
			}
		}
	}
}

bool Unit::isAlive()
{
	return _isAlive;
}