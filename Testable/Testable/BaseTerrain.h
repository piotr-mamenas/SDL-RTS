#ifndef BASETERRAIN_H
#define BASETERRAIN_H

#include <iostream>
#include <list>

#include "GameObject.h"

using namespace std;

class BaseTerrain : public GameObject
{
protected:
	bool _isBlocking;
	unsigned int _blockingXStart;
	unsigned int _blockingYStart;
	unsigned int _blockingXEnd;
	unsigned int _blockingYEnd;

public:
	BaseTerrain(unsigned int initialPositionX, unsigned int initialPositionY);
	bool isBlocked(unsigned int positionX, unsigned int positionY, unsigned int width, unsigned int height);
	unsigned int getWidth();
	unsigned int getHeight();
};

#endif