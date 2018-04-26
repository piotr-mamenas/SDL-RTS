#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "Sprite.h"

class BaseUnit
{
protected:
	BaseUnit();
	unsigned int _id;
	unsigned int _mapPositionX;
	unsigned int _mapPositionY;

	int _currentLife;
	int _damage;
	int _maxLife;
public:
	unsigned int getPositionX();
	unsigned int getPositionY();
};
#endif