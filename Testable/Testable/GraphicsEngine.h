#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Sprite.h"

#include <SDL.h>
#include <list>

using namespace std;

class GraphicsEngine
{
private:
	void _drawSprite(SDL_Surface* screen, Sprite* sprite);
	void _drawUnits();
	list<Sprite*> _unitImages;
	SDL_Window* _gameWindow;
	SDL_Surface* _gameScreen;

public:
	GraphicsEngine(SDL_Window* gameWindow, SDL_Surface* gameScreen);
	void addToScene(Sprite* sprite);
	void drawScene();
};

#endif