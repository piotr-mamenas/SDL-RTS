#ifndef GAMEMAPEDITOR_H
#define GAMEMAPEDITOR_H

#include <iostream>
#include <list>
#include <string>

#include "GameMap.h"
#include "GraphicsEngine.h"
#include "RuleSetManager.h"

using namespace std;

class GameMapEditor
{
private:
	GameMap* _editedMap;
	RuleSetManager* _ruleSet;
	int _defaultMapWidth;
	int _defaultMapHeight;
	int _selectedBrushId;
public:
	GameMapEditor(int defaultMapWidth, int defaultMapHeight, RuleSetManager* ruleSet);
	void loadMap(string mapName);
	void saveMap();
	void start(GraphicsEngine* graphicsEngine, int screenWidth, int screenHeight);
};

#endif