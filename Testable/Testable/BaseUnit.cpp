#include "BaseUnit.h"

BaseUnit::BaseUnit() 
{
}

Sprite* BaseUnit::getSprite()
{
	return _unitSprite;
}

unsigned int BaseUnit::getPositionX()
{
	return _mapPositionX;
}

unsigned int BaseUnit::getPositionY() 
{
	return _mapPositionY;
}