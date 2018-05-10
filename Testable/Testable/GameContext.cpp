#include <iostream>
#include <list>
#include <string>
#include <SDL.h>

#include "BaseUnit.h"
#include "InfantryUnit.h"
#include "GameContext.h"
#include "GraphicsEngine.h"
#include "GameAssetManager.h"
#include "Player.h"
#include "GameTimer.h"
#include "GrassTerrainTile.h"
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
	_gameWindow = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		if (_isWindowMode) 
		{
			_gameWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
		}
		else
		{
			_gameWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_FULLSCREEN);
		}
		
		if (_gameWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			_gameRenderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (_gameRenderer == NULL)
			{
				printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}

			_gameAssetManager = new GameAssetManager(_gameRenderer);
			_graphicsEngine = new GraphicsEngine(_gameRenderer, _gameAssetManager, _screenWidth, _screenHeight);

			BaseUnit* infantry = new InfantryUnit(50, 60);
			BaseUnit* infantry2 = new InfantryUnit(12, 92);
			BaseUnit* infantry3 = new InfantryUnit(30, 155);
			BaseTerrain* fillTerrain = new GrassTerrainTile(0,0);
			GameMap* gameMap = new GameMap(fillTerrain, 2700, 1980);

			list<BaseUnit*> units;
			units.push_back(infantry);
			units.push_back(infantry2);
			units.push_back(infantry3);

			string playerOneRGBColor = "FF0000";
			_currentPlayer = new Player(playerOneRGBColor, units, _screenWidth, _screenHeight);
			_currentPlayer->startNewGame(gameMap);
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
	delete _gameAssetManager;
	delete _graphicsEngine;

	SDL_DestroyRenderer(_gameRenderer);
	SDL_DestroyWindow(_gameWindow);
	_gameRenderer = NULL;
	_gameWindow = NULL;

	SDL_Quit();
}