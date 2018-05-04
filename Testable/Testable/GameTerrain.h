#ifndef GAMETERRAIN_H
#define GAMETERRAIN_H

#include <iostream>
#include <list>

#include "Sprite.h"

using namespace std;

class GameTerrain
{
private:
	Sprite* _terrainSprite;
	int _terrainX;
	int _terrainY;

	bool _isBlocking;
	int _blockingXStart;
	int _blockingYStart;
	int _blockingXEnd;
	int _blockingYEnd;

public:
	GameTerrain();
	bool isBlocked(int positionX, int positionY, int width, int height);
	Sprite* getSprite();
};

#endif