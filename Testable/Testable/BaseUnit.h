#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "Sprite.h"
#include "GameObject.h"

class BaseUnit : public GameObject
{
protected:
	BaseUnit(unsigned int initialPositionX, unsigned int initialPositionY);

	int _currentLife;
	int _damage;
	int _maxLife;

	bool _isAlive;
public:
	bool isAlive();
	void handleEvent(unsigned int clickPositionX, unsigned int clickPositionY, int eventType);
};
#endif