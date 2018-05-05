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
	SDL_Surface* _loadSurface(std::string path);
	void _loadGameResources();
	void _releaseGameResources();
	map<unsigned int, Sprite*> _loadSprite(const char* fileName);

	SDL_Surface* _gameScreen;
	map<unsigned int, Sprite*> _unitSprites;
	map<unsigned int, Sprite*> _terrainSprites;

public:
	GameAssetManager(SDL_Surface* gameScreen);
	~GameAssetManager();
	Sprite* getUnitSprite(int unitId);
	Sprite* getTerrainSprite(int terrainId);
};

#endif