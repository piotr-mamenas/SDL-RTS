#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>
#include <string>

#include <SDL.h>

#include "BaseUnit.h"
#include "GameMap.h"

using namespace std;

class Player
{
private:
	void _handleScrolling(int mousePositionX, int mousePositionY);
	void _resetScrolling();
	string _color;
	list<BaseUnit*> _units;
	GameMap* _gameMap;
	unsigned int _cameraX;
	unsigned int _cameraY;
	unsigned int _screenResolutionX;
	unsigned int _screenResolutionY;
	int _mousePositionX;
	int _mousePositionY;
	bool _scrollingLeft;
	bool _scrollingRight;
	bool _scrollingUp;
	bool _scrollingDown;
public:
	Player(string color, list<BaseUnit*> startingUnits, unsigned int screenResolutionX, unsigned int screenResolutionY);
	void addUnit(BaseUnit* unit);
	list<BaseUnit*> getUnits();
	void setCamera(unsigned int cameraX, unsigned int cameraY);
	unsigned int getCameraX();
	unsigned int getCameraY();
	void handleInteraction(SDL_Event e, list<BaseUnit*> units);
	void scrollCamera();
	void startNewGame(GameMap* gameMap);
};

#endif