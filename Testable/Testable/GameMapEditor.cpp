#include <memory>
#include <string>

#include <SDL.h>

#include "GameMapEditor.h"
#include "GraphicsEngine.h"
#include "Terrain.h"
#include "GameTimer.h"
#include "Player.h"
#include "RuleSetManager.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

GameMapEditor::GameMapEditor(int defaultMapWidth, int defaultMapHeight, std::shared_ptr<RuleSetManager> ruleSet)
{
	_defaultMapWidth = defaultMapWidth;
	_defaultMapHeight = defaultMapHeight;

	_editedMap = std::make_shared<GameMap>(new GameMap(_defaultMapWidth, _defaultMapHeight, ruleSet));
}

void GameMapEditor::loadMap(std::string mapName)
{
	//_editedMap->loadMap(mapName);
}

void GameMapEditor::saveMap()
{

}

void GameMapEditor::start(std::unique_ptr<GraphicsEngine> graphicsEngine, int screenWidth, int screenHeight)
{
	std::unique_ptr<Player> mapEditor = std::make_unique<Player>(new Player("000000", screenWidth, screenHeight));

	SDL_Event e;
	bool quit = false;

	GameTimer fpsTimer;
	GameTimer capTimer;
	int countedFrames = 0;
	fpsTimer.start();

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				
			}

			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_1:
					_selectedBrushId = 1;
					break;

				case SDLK_2:
					_selectedBrushId = 2;
					break;

				case SDLK_3:
					_selectedBrushId = 3;
					break;
				}
			}
		}
		graphicsEngine->refreshScene(_editedMap, mapEditor->getCameraX(), mapEditor->getCameraY());
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			// Capped at 20 atm, but VSync is active so can be turned off if necessary
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
		mapEditor->scrollCamera();
	}
}