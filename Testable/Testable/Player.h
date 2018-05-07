#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>
#include <string>

#include "BaseUnit.h"

using namespace std;

class Player
{
private:
	string _color;
	list<BaseUnit*> _units;
	unsigned int _cameraX;
	unsigned int _cameraY;
public:
	Player(string color, list<BaseUnit*> startingUnits);
	void addUnit(BaseUnit* unit);
	list<BaseUnit*> getUnits();
};

#endif