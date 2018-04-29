#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "Sprite.h"

class BaseUnit
{
protected:
	BaseUnit(unsigned int initialPositionX, unsigned int initialPositionY);
	unsigned int _id;
	unsigned int _mapPositionX;
	unsigned int _mapPositionY;

	int _currentLife;
	int _damage;
	int _maxLife;

	bool _isAlive;
protected:
	int _unitWidth;
	int _unitHeight;
public:
	unsigned int getId();
	unsigned int getPositionX();
	unsigned int getPositionY();
	bool isAlive();
	void handleEvent(SDL_Event* e);
};
#endif