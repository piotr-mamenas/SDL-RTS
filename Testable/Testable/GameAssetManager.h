#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include "Sprite.h"
#include "Unit.h"

#include <SDL.h>
#include <list>
#include <map>
#include <string>

using namespace std;

class GameAssetManager
{
private:
	SDL_Texture * _loadTexture(string path);
	void _loadGameResources();
	void _releaseGameResources();
	void _releaseMap(map<int, Sprite*> spriteMap);
	map<int, Sprite*> _loadSprite(string fileName);
	SDL_Renderer* _gameRenderer;
	map<int, Sprite*> _sprites;
public:
	GameAssetManager(SDL_Renderer* gameRenderer);
	~GameAssetManager();
	Sprite* getSprite(int spriteId);
};

#endif