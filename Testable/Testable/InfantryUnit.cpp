#include "InfantryUnit.h"

#define INFANTRY_HP 40;
#define INFANTRY_DAMAGE 3;
#define INFANTRY_ID 1
#define INFANTRY_WIDTH 16;
#define INFANTRY_HEIGHT 16;

InfantryUnit::InfantryUnit(unsigned int initialPositionX, unsigned int initialPositionY) 
	: BaseUnit(initialPositionX, initialPositionY)
{
	_currentLife = INFANTRY_HP;
	_maxLife = _currentLife;
	_damage = INFANTRY_DAMAGE;
	_id = INFANTRY_ID;
	_unitWidth = INFANTRY_WIDTH;
	_unitHeight = INFANTRY_HEIGHT;
}