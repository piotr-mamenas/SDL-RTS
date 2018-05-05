#include "GameAssetManager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <string>

using namespace std;

GameAssetManager::GameAssetManager(SDL_Surface* gameScreen)
{
	_gameScreen = gameScreen;

	_loadGameResources();
}

GameAssetManager::~GameAssetManager() 
{
	_releaseGameResources();
}

void GameAssetManager::_loadGameResources()
{
	_terrainSprites = _loadSprite("terrain_images.dat");
	_unitSprites = _loadSprite("unit_images.dat");
}

map<unsigned int, Sprite*> GameAssetManager::_loadSprite(const char* fileName)
{
	unsigned int id;
	string path;

	map<unsigned int, Sprite*> sprites;
	ifstream spriteFile(fileName);

	while (spriteFile >> id >> path)
	{
		SDL_Surface* optimizedSurface = _loadSurface(path);
		Sprite* sprite = new Sprite(optimizedSurface);
		sprites.insert(pair<unsigned int, Sprite*>(id, sprite));
	}
	return sprites;
}

SDL_Surface* GameAssetManager::_loadSurface(string path)
{
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, _gameScreen->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

void GameAssetManager::_releaseGameResources()
{
	std::map<unsigned int, Sprite*>::iterator unitIterator;
	for(unitIterator = _unitSprites.begin(); unitIterator != _unitSprites.end(); unitIterator++)
	{
		Sprite* unitSprite = unitIterator -> second;
		SDL_FreeSurface(unitSprite -> getImage() );
	}
}

Sprite* GameAssetManager::getUnitSprite(int unitId)
{
	map<unsigned int, Sprite*>::iterator unitIterator = _unitSprites.find(unitId);
	if (unitIterator != _unitSprites.end()) 
	{
		return unitIterator -> second;
	}
	return NULL;
}

Sprite* GameAssetManager::getTerrainSprite(int terrainId)
{
	map<unsigned int, Sprite*>::iterator terrainIterator = _terrainSprites.find(terrainId);
	if (terrainIterator != _terrainSprites.end())
	{
		return terrainIterator -> second;
	}
	return NULL;
}