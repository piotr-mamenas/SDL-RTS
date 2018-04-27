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

GameContext::GameContext(int screenWidth, int screenHeight, bool isMinimized) 
{
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;
	
	init(isMinimized);
}

bool GameContext::init(bool isMinimized) 
{
	bool success = true;
	GraphicsEngine* graphicsEngine = NULL;
	GameAssetManager* gameAssetManager = NULL;

	gameWindow = NULL;
	mainSurface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		if (isMinimized) 
		{
			gameWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN, SDL_WINDOW_OPENGL);
		}
		else
		{
			gameWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_FULLSCREEN, SDL_WINDOW_OPENGL);
		}
		
		if (gameWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			mainSurface = SDL_GetWindowSurface(gameWindow);
			gameAssetManager = new GameAssetManager(mainSurface);
			graphicsEngine = new GraphicsEngine(gameWindow, mainSurface, gameAssetManager);

			BaseUnit* infantry = new InfantryUnit(50, 60);
			BaseUnit* infantry2 = new InfantryUnit(12, 92);
			BaseUnit* infantry3 = new InfantryUnit(30, 155);

			list<BaseUnit*> units;
			units.push_back(infantry);
			units.push_back(infantry2);
			units.push_back(infantry3);

			graphicsEngine->drawScene(units);


		}
	}
	return success;
}

void GameContext::close()
{
	SDL_FreeSurface(mainSurface);
	mainSurface = NULL;

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	SDL_Quit();
}

void GameContext::_updateGraphics(GraphicsEngine* graphicsEngine)
{
	for (Player player : _players)
	{
		for (BaseUnit unit : player.getUnits())
		{
			//graphicsEngine -> addToScene(unit.getSprite());
			// get coordinates
		}
	}
	
}