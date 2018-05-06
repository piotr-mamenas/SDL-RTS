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
	void _drawTexture(SDL_Texture* texture, unsigned int positionX, unsigned int positionY);
	void _drawUnits(list<BaseUnit*> units);
	void _drawGameMap(GameMap* gameMap);
	SDL_Renderer* _gameRenderer;
	GameAssetManager* _gameAssetManager;

public:
	GraphicsEngine(SDL_Renderer* gameRenderer, GameAssetManager* assetManager);
	~GraphicsEngine();
	void refreshScene(list<BaseUnit*> units, GameMap* gameMap);
	void refreshScene(GameMap* gameMap);
};

#endif