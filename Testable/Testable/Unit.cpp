#include <iostream>
#include <string>

#include "Unit.h"
#include "GameObject.h"

#include <nlohmann\json.hpp>

using json = nlohmann::json;

Unit::Unit(int initialPositionX, int initialPositionY, Unit* unitTemplate)
	: GameObject(initialPositionX, initialPositionY)
{
	_id = unitTemplate->getId();
	_isAlive = true;
	_currentLife = unitTemplate->getMaxLife();
	_maxLife = unitTemplate->getMaxLife();
	_damage = unitTemplate->getDamage();
	_unitName = unitTemplate->getName();
	_width = unitTemplate->getWidth();
	_height = unitTemplate->getHeight();
}

Unit::Unit(json unitJson)
	: GameObject(unitJson)
{

}

int Unit::getMaxLife()
{
	return _maxLife;
}

int Unit::getDamage()
{
	return _damage;
}

string Unit::getName()
{
	return _unitName;
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
	_currentLife = json.at("maxLife").get<int>();
	_maxLife = json.at("maxLife").get<int>();
	_unitName = json.at("unitName").get<string>();
	_width = json.at("width").get<int>();
	_height = json.at("height").get<int>();
	_damage = json.at("damage").get<int>();
}

bool Unit::isAlive()
{
	return _isAlive;
}

