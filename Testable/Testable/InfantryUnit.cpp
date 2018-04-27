#include "InfantryUnit.h"

#define INFANTRY_HP 40;
#define INFANTRY_DAMAGE 3;

InfantryUnit::InfantryUnit(unsigned int initialPositionX, unsigned int initialPositionY) 
	: BaseUnit(initialPositionX, initialPositionY)
{
	_currentLife = INFANTRY_HP;
	_maxLife = _currentLife;
	_damage = INFANTRY_DAMAGE;
}