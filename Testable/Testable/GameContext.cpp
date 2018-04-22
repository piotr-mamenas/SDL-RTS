#include <iostream>
#include <SDL.h>

#include "BaseUnit.h"
#include "InfantryUnit.h"
#include "GameContext.h"

bool GameContext::Init() 
{
	bool success = true;

	gameWindow = NULL;
	mainSurface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		gameWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN, SDL_WINDOW_OPENGL);
		if (gameWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			mainSurface = SDL_GetWindowSurface(gameWindow);
		}
	}
	return success;
}

void GameContext::Close()
{
	SDL_FreeSurface(mainSurface);
	mainSurface = NULL;

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	SDL_Quit();
}

bool GameContext::SetBrush()
{
	bool success = true;

	return true;
}