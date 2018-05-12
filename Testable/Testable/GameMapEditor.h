#ifndef GAMEMAPEDITOR_H
#define GAMEMAPEDITOR_H

#include <iostream>
#include <list>
#include <string>

#include "GameMap.h"
#include "GraphicsEngine.h"

using namespace std;

class GameMapEditor
{
private:
	GameMap* _editedMap;
	int _defaultMapWidth;
	int _defaultMapHeight;
	int _selectedBrushId;
public:
	GameMapEditor(int defaultMapWidth, int defaultMapHeight);
	void loadMap(string mapName);
	void saveMap();
	void start(GraphicsEngine* graphicsEngine, int screenWidth, int screenHeight);
};

#endif