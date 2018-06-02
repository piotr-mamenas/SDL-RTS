#ifndef BASETERRAIN_H
#define BASETERRAIN_H

#include <iostream>
#include <list>

#include "GameObject.h"

#include <nlohmann\json.hpp>

using namespace std;
using json = nlohmann::json;

class Terrain : public GameObject
{
protected:
	bool _isBlocking;
	int _blockingXStart;
	int _blockingYStart;
	int _blockingXEnd;
	int _blockingYEnd;

public:
	Terrain(int initialPositionX, int initialPositionY, Terrain* terrainTemplate);
	Terrain(json terrainJson);
	bool isBlocked(int positionX, int positionY, int width, int height);
	void deserializeFrom(json json) override;
};

#endif