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
	sdl2::TexturePtr _loadTexture(std::string path);
	void _loadGameResources();
	void _releaseGameResources();
	void _releaseMap(std::map<int, std::unique_ptr<Sprite>> spriteMap);
	std::map<int, std::unique_ptr<Sprite>> _loadSprite(std::string fileName);
	sdl2::RendererSharedPtr _gameRenderer;
	std::map<int, std::unique_ptr<Sprite>> _sprites;
public:
	GameAssetManager(sdl2::RendererSharedPtr gameRenderer);
	~GameAssetManager();
	std::unique_ptr<Sprite> getSprite(int spriteId);
};

#endif