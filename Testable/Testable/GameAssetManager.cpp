#include "GameAssetManager.h"

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <string>

#include "GameObject.h"
#include "Terrain.h"
#include "Unit.h"

#include <SDL.h>
#include <SDL_image.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

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
	_sprites = _loadSprite("sprites.json");
}

map<int, Sprite*> GameAssetManager::_loadSprite(string fileName)
{
	int spriteId;
	int spriteWidth;
	int spriteHeight;
	string path;

	map<int, Sprite*> spriteMap;
	try
	{
		//TODO: Issue with file load
		ifstream spriteFile(fileName);
		json sprites;
		spriteFile >> sprites;

		for (auto& sprite : sprites.at("sprites"))
		{
			spriteId = sprite.at("id").get<int>();
			spriteWidth = sprite.at("width").get<int>();
			spriteHeight = sprite.at("height").get<int>();
			path = sprite.at("spriteSheetImage").get<string>();

			SDL_Texture* texture = _loadTexture(path);
			Sprite* sprite = new Sprite(texture, spriteWidth, spriteHeight);
			spriteMap.insert(pair<int, Sprite*>(spriteId, sprite));
		}
		return spriteMap;
	}
	catch (json::parse_error& e)
	{
		cout << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << endl;

		return spriteMap;
	}
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
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0));
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
	_releaseMap(_sprites);
}

void GameAssetManager::_releaseMap(std::map<int, Sprite*> spriteMap)
{
	std::map<int, Sprite*>::iterator spriteIterator;
	for (spriteIterator = spriteMap.begin(); spriteIterator != spriteMap.end(); spriteIterator++)
	{
		Sprite* sprite = spriteIterator->second;
		SDL_DestroyTexture(sprite -> getTexture());
	}
}

Sprite* GameAssetManager::getSprite(int spriteId)
{
	map<int, Sprite*>::iterator spriteIterator = _sprites.find(spriteId);
	if (spriteIterator != _sprites.end())
	{
		return spriteIterator->second;
	}
	return NULL;
}

