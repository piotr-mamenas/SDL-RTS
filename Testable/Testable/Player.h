#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>

#include "BaseUnit.h"

using namespace std;

class Player
{
private:
	unsigned char* _color;
	list<BaseUnit> _units;
public:
	Player(unsigned char* color, list<BaseUnit> startingUnits);
	void addUnit(BaseUnit unit);
	list<BaseUnit> getUnits();
};

#endif