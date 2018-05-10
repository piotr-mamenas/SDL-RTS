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
	void _releaseMap(std::map<unsigned int, Sprite*> spriteMap);
	map<unsigned int, Sprite*> _loadSprite(const char* fileName);
	SDL_Renderer* _gameRenderer;
	map<unsigned int, Sprite*> _unitSprites;
	map<unsigned int, Sprite*> _terrainSprites;

	Sprite* _findSprite(int spriteId, map<unsigned int, Sprite*> sprites);
	Sprite* _getUnitSprite(int unitId);
	Sprite* _getTerrainSprite(int terrainId);
public:
	GameAssetManager(SDL_Renderer* gameRenderer);
	~GameAssetManager();
	Sprite* getSprite(unsigned int spriteId);
};

#endif