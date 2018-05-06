#ifndef GAMEMAPEDITOR_H
#define GAMEMAPEDITOR_H

#include <iostream>
#include <list>

#include "GameMap.h"
#include "GraphicsEngine.h"

using namespace std;

class GameMapEditor
{
private:
	GameMap* _editedMap;
	unsigned int _defaultMapWidth;
	unsigned int _defaultMapHeight;
public:
	GameMapEditor(unsigned int defaultMapWidth, unsigned int defaultMapHeight);
	void start(GraphicsEngine* graphicsEngine);
};

#endif