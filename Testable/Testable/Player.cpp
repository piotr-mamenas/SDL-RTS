#include <iostream>
#include <list>
#include <string>

#include "Player.h"

Player::Player(string color, list<BaseUnit*> startingUnits)
{
	_units = startingUnits;
	_color = color;
}

void Player::addUnit(BaseUnit* unit)
{
	_units.push_back(unit);
}

list<BaseUnit*> Player::getUnits()
{
	return _units;
}