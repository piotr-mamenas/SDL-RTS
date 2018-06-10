#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <SDL.h>

#include "Unit.h"
#include "Terrain.h"
#include "GameContext.h"
#include "GraphicsEngine.h"
#include "GameAssetManager.h"
#include "Player.h"
#include "GameTimer.h"
#include "GameMap.h"

#define GAME_NAME "C++ RTS"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

GameContext::GameContext(int screenWidth, int screenHeight, bool isWindowMode) 
{
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;
	_isWindowMode = isWindowMode;
}

bool GameContext::init() 
{
	bool success = true;
	bool isMapEditorMode = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		if (_isWindowMode) 
		{
			_gameWindow = sdl2::WindowSharedPtr(SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN));
		}
		else
		{
			_gameWindow = sdl2::WindowSharedPtr(SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_FULLSCREEN));
		}
		
		if (_gameWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
			success = false;
		}
		else
		{
			_gameRenderer = sdl2::RendererSharedPtr(SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
			if (_gameRenderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError();
				success = false;
			}

			_gameAssetManager = std::make_shared<GameAssetManager>(new GameAssetManager(_gameRenderer));
			_graphicsEngine = std::make_shared<GraphicsEngine>(new GraphicsEngine(_gameRenderer, _gameAssetManager, _screenWidth, _screenHeight));
			_gameRuleSet = std::make_shared<RuleSetManager>(new RuleSetManager(true));

			_gameRuleSet->getUnitTemplate(1);
			std::unique_ptr<Unit> infantry = std::make_unique<Unit>(new Unit(50, 60,_gameRuleSet->getUnitTemplate(1)));
			std::unique_ptr<Unit> infantry2 = std::make_unique<Unit>(new Unit(12, 92, _gameRuleSet->getUnitTemplate(1)));
			std::unique_ptr<Unit> infantry3 = std::make_unique<Unit>(new Unit(30, 155, _gameRuleSet->getUnitTemplate(1)));
			std::shared_ptr<Terrain> fillTerrain = std::make_unique<Terrain>(new Terrain(0,0, _gameRuleSet->getTerrainTemplate(1)));
			std::shared_ptr<GameMap> gameMap = std::make_shared<GameMap>(new GameMap(fillTerrain, 2700, 1980, _gameRuleSet));
			gameMap->loadMap("skirmish_map");

			std::vector<std::unique_ptr<Unit>> units;
			units.push_back(infantry);
			units.push_back(infantry2);
			units.push_back(infantry3);

			std::string playerOneRGBColor = "FF0000";
			_currentPlayer = std::make_shared<Player>(new Player(playerOneRGBColor, units, _screenWidth, _screenHeight));
			_currentPlayer-> startNewGame(gameMap);
			_currentPlayer->setCamera(0, 0);
			SDL_Event e;
			bool quit = false;
			
			GameTimer fpsTimer;
			GameTimer capTimer;
			int countedFrames = 0;
			fpsTimer.start();

			while (!quit) 
			{
				capTimer.start();
				while (SDL_PollEvent(&e)) 
				{
					if (e.type == SDL_QUIT) 
					{
						quit = true;
					}
					_currentPlayer->handleInteraction(e, units);
				}
				_graphicsEngine->refreshScene(units, gameMap, _currentPlayer->getCameraX(), _currentPlayer->getCameraY());
				int frameTicks = capTimer.getTicks();
				if (frameTicks < SCREEN_TICKS_PER_FRAME)
				{
					// Capped at 20 atm, but VSync is active so can be turned off if necessary
					SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
				}
				_currentPlayer->scrollCamera();
			}
		}
	}
	return success;
}

void GameContext::close()
{
	SDL_Quit();
}