#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "Sprite.h"
#include "GameObject.h"

#include <string>

using namespace std;

class Unit : public GameObject
{
protected:
	int _unitId;
	int _currentLife;
	int _damage;
	int _maxLife;
	string _unitName;

	bool _isAlive;
public:
	Unit(int unitId, int initialPositionX, int initialPositionY);
	bool isAlive();
	void handleEvent(int clickPositionX, int clickPositionY, int eventType);
};
#endif