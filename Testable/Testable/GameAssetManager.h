#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include "Sprite.h"
#include "Unit.h"

#include <SDL.h>
#include <map>
#include <string>
#include <memory>

class GameAssetManager
{
private:
	sdl2::TextureSharedPtr _loadTexture(std::string path);
	void _loadGameResources();
	std::map<int, std::shared_ptr<Sprite>> _loadSprite(std::string fileName);
	sdl2::RendererSharedPtr _gameRenderer;
	std::map<int, std::shared_ptr<Sprite>> _sprites;
public:
	GameAssetManager(sdl2::RendererSharedPtr gameRenderer);
	std::shared_ptr<Sprite> getSprite(int spriteId);
};

#endif