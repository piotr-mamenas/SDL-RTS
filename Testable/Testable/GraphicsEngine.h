#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Sprite.h"
#include "Unit.h"
#include "GameAssetManager.h"
#include "GameMap.h"

#include <SDL.h>
#include <memory>
#include <vector>

class GraphicsEngine
{
private:
	void _drawTexture(std::unique_ptr<SDL_Texture> texture, std::unique_ptr<SDL_Rect> clip, unsigned int positionX, unsigned int positionY);
	void _drawUnits(std::vector<std::unique_ptr<Unit>> units);
	void _drawGameObject(std::unique_ptr<GameObject> object);
	void _drawGameMap(std::unique_ptr<GameMap> gameMap);
	void _setCamera(unsigned int cameraX, unsigned int cameraY);
	bool _isInCamera(unsigned int positionX, unsigned int positionY, unsigned int width, unsigned int height);
	std::unique_ptr<SDL_Renderer> _gameRenderer;
	std::unique_ptr<GameAssetManager> _gameAssetManager;

	unsigned int _currentPlayerCameraX;
	unsigned int _currentPlayerCameraY;
	unsigned int _windowResolutionX;
	unsigned int _windowResolutionY;
public:
	GraphicsEngine(std::unique_ptr<SDL_Renderer> gameRenderer, std::unique_ptr<GameAssetManager> assetManager, unsigned int resolutionX, unsigned int resolutionY);
	~GraphicsEngine();
	void refreshScene(std::vector<std::unique_ptr<Unit>> units, std::unique_ptr<GameMap> gameMap, unsigned int cameraX, unsigned int cameraY);
	void refreshScene(std::unique_ptr<GameMap> gameMap, unsigned int cameraX, unsigned int cameraY);
};

#endif