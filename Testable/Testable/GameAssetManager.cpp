#include "GameAssetManager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <string>
#include "GameObject.h"
#include "BaseTerrain.h"
#include "BaseUnit.h"

using namespace std;

GameAssetManager::GameAssetManager(SDL_Renderer* gameRenderer)
{
	_gameRenderer = gameRenderer;

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
		SDL_Texture* texture = _loadTexture(path);
		Sprite* sprite = new Sprite(texture);
		sprites.insert(pair<unsigned int, Sprite*>(id, sprite));
	}
	return sprites;
}

SDL_Texture* GameAssetManager::_loadTexture(string path)
{
	SDL_Texture* loadedTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		loadedTexture = SDL_CreateTextureFromSurface(_gameRenderer, loadedSurface);
		if (loadedTexture == NULL)
		{
			printf("Unable to create texture %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}
	SDL_FreeSurface(loadedSurface);
	return loadedTexture;
}

void GameAssetManager::_releaseGameResources()
{
	std::map<unsigned int, Sprite*>::iterator unitIterator;
	for(unitIterator = _unitSprites.begin(); unitIterator != _unitSprites.end(); unitIterator++)
	{
		Sprite* unitSprite = unitIterator -> second;
		SDL_DestroyTexture(unitSprite -> getTexture() );
	}

	std::map<unsigned int, Sprite*>::iterator terrainIterator;
	for (terrainIterator = _terrainSprites.begin(); terrainIterator != _terrainSprites.end(); terrainIterator++)
	{
		Sprite* terrainSprite = terrainIterator->second;
		SDL_DestroyTexture(terrainSprite->getTexture());
	}
}

Sprite* GameAssetManager::_getUnitSprite(int unitId)
{
	map<unsigned int, Sprite*>::iterator unitIterator = _unitSprites.find(unitId);
	if (unitIterator != _unitSprites.end()) 
	{
		return unitIterator -> second;
	}
	return NULL;
}

Sprite* GameAssetManager::_getTerrainSprite(int terrainId)
{
	map<unsigned int, Sprite*>::iterator terrainIterator = _terrainSprites.find(terrainId);
	if (terrainIterator != _terrainSprites.end())
	{
		return terrainIterator -> second;
	}
	return NULL;
}

Sprite* GameAssetManager::getSprite(unsigned int spriteId)
{
	if (spriteId < 2500)
	{
		return _getUnitSprite(spriteId);
	}
	else
	{
		return _getTerrainSprite(spriteId);
	}
}

