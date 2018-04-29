#include <iostream>
#include <list>
#include <SDL.h>

#include "BaseUnit.h"
#include "InfantryUnit.h"
#include "GameContext.h"
#include "GraphicsEngine.h"
#include "GameAssetManager.h"
#include "Player.h"

#define GAME_NAME "C++ RTS"

GameContext::GameContext(int screenWidth, int screenHeight, bool isWindowMode) 
{
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;
	_isWindowMode = isWindowMode;
}

bool GameContext::init() 
{
	bool success = true;
	_gameWindow = NULL;
	_mainSurface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		if (_isWindowMode) 
		{
			_gameWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		}
		else
		{
			_gameWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_FULLSCREEN);
		}
		
		if (_gameWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			_mainSurface = SDL_GetWindowSurface(_gameWindow);
			_gameAssetManager = new GameAssetManager(_mainSurface);
			_graphicsEngine = new GraphicsEngine(_gameWindow, _mainSurface, _gameAssetManager);

			BaseUnit* infantry = new InfantryUnit(50, 60);
			BaseUnit* infantry2 = new InfantryUnit(12, 92);
			BaseUnit* infantry3 = new InfantryUnit(30, 155);

			list<BaseUnit*> units;
			units.push_back(infantry);
			units.push_back(infantry2);
			units.push_back(infantry3);

			_graphicsEngine -> drawScene(units);

			SDL_Event e;
			bool quit = false;
			while (!quit) 
			{
				while (SDL_PollEvent(&e)) 
				{
					if (e.type == SDL_QUIT) 
					{
						quit = true;
					}

					for (BaseUnit* unit : units)
					{
						unit->handleEvent(&e);
					}
				}
			}
		}
	}
	return success;
}

void GameContext::close()
{
	delete _gameAssetManager;

	SDL_FreeSurface(_mainSurface);
	_mainSurface = NULL;

	SDL_DestroyWindow(_gameWindow);
	_gameWindow = NULL;

	SDL_Quit();
}