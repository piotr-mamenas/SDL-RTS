#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "Sprite.h"

class BaseUnit
{
protected:
	BaseUnit();

	Sprite* _unitSprite;

	int _currentLife;
	int _damage;
	int _maxLife;
public:
	Sprite* getSprite();
};
#endif