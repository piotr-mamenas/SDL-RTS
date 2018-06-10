#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SDL.h>
#include <iostream>
#include <vector>
#include <memory>

#include "GraphicsEngine.h"
#include "Player.h"
#include "RuleSetManager.h"

class GameContext
{
private:
	std::unique_ptr<SDL_Window> _gameWindow;
	std::unique_ptr<SDL_Renderer> _gameRenderer;
	std::unique_ptr<GraphicsEngine> _graphicsEngine;
	std::unique_ptr<GameAssetManager> _gameAssetManager = NULL;
	std::unique_ptr<RuleSetManager> _gameRuleSet = NULL;
	std::unique_ptr<Player> _currentPlayer = NULL;
	std::vector<std::unique_ptr<Player>> _players;
	
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