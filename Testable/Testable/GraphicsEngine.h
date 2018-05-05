#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Sprite.h"
#include "BaseUnit.h"
#include "GameAssetManager.h"
#include "GameMap.h"

#include <SDL.h>
#include <list>

using namespace std;

class GraphicsEngine
{
private:
	void _drawImage(SDL_Surface* screen, SDL_Surface* image, unsigned int positionX, unsigned int positionY);
	void _drawUnits(list<BaseUnit*> units);
	void _drawGameMap(GameMap* gameMap);
	list<Sprite*> _unitImages;
	SDL_Window* _gameWindow;
	SDL_Surface* _gameScreen;
	GameAssetManager* _gameAssetManager;

public:
	GraphicsEngine(SDL_Window* gameWindow, SDL_Surface* gameScreen, GameAssetManager* assetManager);
	void addToScene(Sprite* sprite);
	void drawScene(list<BaseUnit*> units, GameMap* gameMap);
};

#endif