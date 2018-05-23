#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SDL.h>
#include <iostream>
#include <list>

#include "GraphicsEngine.h"
#include "Player.h"
#include "RuleSetManager.h"

using namespace std;

class GameContext
{
private:
	SDL_Window* _gameWindow = NULL;
	SDL_Renderer* _gameRenderer = NULL;
	GraphicsEngine* _graphicsEngine = NULL;
	GameAssetManager* _gameAssetManager = NULL;
	RuleSetManager* _gameRuleSet = NULL;
	Player* _currentPlayer = NULL;
	list<Player*> _players;
	
	int _screenWidth;
	int _screenHeight;
	int _windowStatus;
	bool _isWindowMode;
public:
	GameContext(int screenWidth, int screenHeight, bool isMinimized);
	bool init();
	void close();
};

#endif