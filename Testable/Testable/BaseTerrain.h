#ifndef BASETERRAIN_H
#define BASETERRAIN_H

#include <iostream>
#include <list>

using namespace std;

class BaseTerrain
{
protected:
	unsigned int _id;
	unsigned int _terrainPositionX;
	unsigned int _terrainPositionY;
	unsigned int _terrainWidth;
	unsigned int _terrainHeight;

	bool _isBlocking;
	int _blockingXStart;
	int _blockingYStart;
	int _blockingXEnd;
	int _blockingYEnd;

public:
	BaseTerrain(unsigned int initialPositionX, unsigned int initialPositionY);
	bool isBlocked(int positionX, int positionY, int width, int height);
	unsigned int getId();
	unsigned int getPositionX();
	unsigned int getPositionY();
	unsigned int getWidth();
	unsigned int getHeight();
};

#endif