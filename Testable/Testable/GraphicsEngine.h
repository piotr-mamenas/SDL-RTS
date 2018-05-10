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
	void _drawTexture(SDL_Texture* texture, SDL_Rect* clip, unsigned int positionX, unsigned int positionY);
	void _drawUnits(list<BaseUnit*> units);
	void _drawGameObject(GameObject* object);
	void _drawGameMap(GameMap* gameMap);
	void _setCamera(unsigned int cameraX, unsigned int cameraY);
	bool _isInCamera(unsigned int positionX, unsigned int positionY, unsigned int width, unsigned int height);
	SDL_Renderer* _gameRenderer;
	GameAssetManager* _gameAssetManager;

	unsigned int _currentPlayerCameraX;
	unsigned int _currentPlayerCameraY;
	unsigned int _windowResolutionX;
	unsigned int _windowResolutionY;

public:
	GraphicsEngine(SDL_Renderer* gameRenderer, GameAssetManager* assetManager, unsigned int resolutionX, unsigned int resolutionY);
	~GraphicsEngine();
	void refreshScene(list<BaseUnit*> units, GameMap* gameMap, unsigned int cameraX, unsigned int cameraY);
	void refreshScene(GameMap* gameMap, unsigned int cameraX, unsigned int cameraY);
};

#endif