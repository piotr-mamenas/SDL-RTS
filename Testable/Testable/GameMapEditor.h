#ifndef GAMEMAPEDITOR_H
#define GAMEMAPEDITOR_H

#include <string>
#include <memory>

#include "GameMap.h"
#include "GraphicsEngine.h"
#include "RuleSetManager.h"

class GameMapEditor
{
private:
	std::shared_ptr<GameMap> _editedMap;
	std::shared_ptr<RuleSetManager> _ruleSet;
	int _defaultMapWidth;
	int _defaultMapHeight;
	int _selectedBrushId;
public:
	GameMapEditor(int defaultMapWidth, int defaultMapHeight, std::shared_ptr<RuleSetManager> ruleSet);
	void loadMap(std::string mapName);
	void saveMap();
	void start(std::unique_ptr<GraphicsEngine> graphicsEngine, int screenWidth, int screenHeight);
};

#endif