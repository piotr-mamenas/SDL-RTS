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
	std::unique_ptr<SDL_Texture> _loadTexture(std::string path);
	void _loadGameResources();
	void _releaseGameResources();
	void _releaseMap(std::map<int, std::unique_ptr<Sprite>> spriteMap);
	std::map<int, std::unique_ptr<Sprite>> _loadSprite(std::string fileName);
	std::shared_ptr<SDL_Renderer> _gameRenderer;
	std::map<int, std::unique_ptr<Sprite>> _sprites;
public:
	GameAssetManager(std::shared_ptr<SDL_Renderer> gameRenderer);
	~GameAssetManager();
	std::unique_ptr<Sprite> getSprite(int spriteId);
};

#endif