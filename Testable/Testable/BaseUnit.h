#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "Sprite.h"

class BaseUnit
{
protected:
	BaseUnit();

	Sprite* _unitSprite;

	unsigned int _mapPositionX;
	unsigned int _mapPositionY;

	int _currentLife;
	int _damage;
	int _maxLife;
public:
	Sprite* getSprite();
	unsigned int getPositionX();
	unsigned int getPositionY();
};
#endif