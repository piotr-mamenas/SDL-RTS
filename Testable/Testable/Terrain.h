#ifndef BASETERRAIN_H
#define BASETERRAIN_H

#include <iostream>
#include <list>

#include "GameObject.h"

using namespace std;

class Terrain : public GameObject
{
protected:
	bool _isBlocking;
	int _blockingXStart;
	int _blockingYStart;
	int _blockingXEnd;
	int _blockingYEnd;

public:
	Terrain(int terrainId, int initialPositionX, int initialPositionY);
	bool isBlocked(int positionX, int positionY, int width, int height);
};

#endif