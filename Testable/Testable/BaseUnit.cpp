#include "BaseUnit.h"

BaseUnit::BaseUnit(unsigned int initialPositionX, unsigned int initialPositionY) 
{
	_mapPositionX = initialPositionX;
	_mapPositionY = initialPositionY;
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