#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>
#include <string>

#include <SDL.h>

#include "Unit.h"
#include "GameMap.h"

using namespace std;

class Player
{
private:
	void _handleScrolling(int mousePositionX, int mousePositionY);
	void _resetScrolling();
	string _color;
	list<Unit*> _units;
	list<Player*> _hostilePlayers;
	GameMap* _gameMap;
	int _cameraX;
	int _cameraY;
	int _screenResolutionX;
	int _screenResolutionY;
	int _mousePositionX;
	int _mousePositionY;
	bool _scrollingLeft;
	bool _scrollingRight;
	bool _scrollingUp;
	bool _scrollingDown;
public:
	Player(string color, list<Unit*> startingUnits, int screenResolutionX, int screenResolutionY);
	Player(string color, int screenResolutionX, int screenResolutionY);
	void addUnit(Unit* unit);
	list<Unit*> getUnits();

	void setCamera(int cameraX, int cameraY);
	int getCameraX();
	int getCameraY();
	void handleInteraction(SDL_Event e, list<Unit*> units);
	void scrollCamera();

	void startNewGame(GameMap* gameMap);
	void setPlayerHostile(Player* player);
};

#endif