#include <SDL.h>

#include "GameMapEditor.h"
#include "GraphicsEngine.h"

GameMapEditor::GameMapEditor(unsigned int defaultMapWidth, unsigned int defaultMapHeight)
{
	_defaultMapWidth = defaultMapWidth;
	_defaultMapHeight = defaultMapHeight;
	_editedMap = new GameMap(_defaultMapWidth, _defaultMapHeight);
}

void GameMapEditor::start(GraphicsEngine* graphicsEngine)
{
	SDL_Event e;
	bool quit = false;
	int brushId = 1;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
			{
				graphicsEngine->refreshScene(_editedMap);
			}
		}
	}
}