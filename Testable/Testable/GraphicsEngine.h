#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Sprite.h"
#include "BaseUnit.h"

#include <SDL.h>
#include <list>

using namespace std;

class GraphicsEngine
{
private:
	void _drawSprite(SDL_Surface* screen, Sprite* sprite, unsigned int positionX, unsigned int positionY);
	void _drawUnits(list<BaseUnit> units);
	list<Sprite*> _unitImages;
	SDL_Window* _gameWindow;
	SDL_Surface* _gameScreen;
	SDL_Surface* _loadSurface(std::string path);

public:
	GraphicsEngine(SDL_Window* gameWindow, SDL_Surface* gameScreen);
	void addToScene(Sprite* sprite);
	void drawScene(list<BaseUnit> units);
};

#endif