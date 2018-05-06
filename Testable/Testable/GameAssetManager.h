#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include "Sprite.h"
#include "BaseUnit.h"

#include <SDL.h>
#include <list>
#include <map>

using namespace std;

class GameAssetManager
{
private:
	SDL_Texture * _loadTexture(string path);
	void _loadGameResources();
	void _releaseGameResources();
	map<unsigned int, Sprite*> _loadSprite(const char* fileName);

	SDL_Renderer* _gameRenderer;
	map<unsigned int, Sprite*> _unitSprites;
	map<unsigned int, Sprite*> _terrainSprites;

public:
	GameAssetManager(SDL_Renderer* gameRenderer);
	~GameAssetManager();
	Sprite* getSprite(GameObject* forObjectStore, unsigned int spriteId);
	Sprite* getUnitSprite(int unitId);
	Sprite* getTerrainSprite(int terrainId);
};

#endif