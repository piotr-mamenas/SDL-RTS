#include "Unit.h"
#include "GameObject.h"

#include <iostream>
#include <string>
#include <nlohmann\json.hpp>

using json = nlohmann::json;

Unit::Unit(int unitId, int initialPositionX, int initialPositionY)
	: GameObject(unitId, initialPositionX, initialPositionY)
{
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

void Unit::deserializeFrom(json json)
{
	_id = json.at("id").get<int>();
	_spriteId = json.at("spriteId").get<int>();
	_currentLife = json.at("maxLife");
	_maxLife = json.at("maxLife");
	_width = json.at("width");
	_height = json.at("height");
	_damage = json.at("damage");
}

bool Unit::isAlive()
{
	return _isAlive;
}

