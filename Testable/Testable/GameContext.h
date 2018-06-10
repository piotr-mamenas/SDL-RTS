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
	std::shared_ptr<SDL_Window> _gameWindow;
	std::shared_ptr<SDL_Renderer> _gameRenderer;
	std::shared_ptr<GraphicsEngine> _graphicsEngine;
	std::shared_ptr<GameAssetManager> _gameAssetManager;
	std::shared_ptr<RuleSetManager> _gameRuleSet;
	std::shared_ptr<Player> _currentPlayer;
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