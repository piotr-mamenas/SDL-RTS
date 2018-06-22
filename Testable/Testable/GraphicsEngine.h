#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Sprite.h"
#include "Unit.h"
#include "GameAssetManager.h"
#include "GameMap.h"

#include <memory>
#include <vector>

#include <SDL.h>
#include "SDLDeleter.h"

class GraphicsEngine
{
private:
	void _drawTexture(sdl2::TextureSharedPtr texture, SDL_Rect clip, unsigned int positionX, unsigned int positionY);
	void _drawUnits(std::vector<std::unique_ptr<Unit>> units);
	void _drawGameObject(GameObject* object);
	void _drawGameMap(std::shared_ptr<GameMap> gameMap);
	void _setCamera(unsigned int cameraX, unsigned int cameraY);
	bool _isInCamera(unsigned int positionX, unsigned int positionY, unsigned int width, unsigned int height);
	sdl2::RendererSharedPtr _gameRenderer;
	std::shared_ptr<GameAssetManager> _gameAssetManager;

	unsigned int _currentPlayerCameraX;
	unsigned int _currentPlayerCameraY;
	unsigned int _windowResolutionX;
	unsigned int _windowResolutionY;
public:
	GraphicsEngine(sdl2::RendererSharedPtr gameRenderer, std::shared_ptr<GameAssetManager> assetManager, unsigned int resolutionX, unsigned int resolutionY);
	~GraphicsEngine();
	void refreshScene(std::vector<std::unique_ptr<Unit>> units, std::shared_ptr<GameMap> gameMap, unsigned int cameraX, unsigned int cameraY);
	void refreshScene(std::shared_ptr<GameMap> gameMap, unsigned int cameraX, unsigned int cameraY);
};

#endif