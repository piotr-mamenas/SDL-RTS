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
	SDL_Surface* _gameScreen;
	map<unsigned int, SDL_Surface*> _units;

public:
	GameAssetManager(SDL_Surface* gameScreen);
	SDL_Surface* getUnitImage(int unitId);
};

#endif