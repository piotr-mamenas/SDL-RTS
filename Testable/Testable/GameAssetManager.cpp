#include "GameAssetManager.h"

#include <iostream>
#include <vector>
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

using json = nlohmann::json;

GameAssetManager::GameAssetManager(sdl2::RendererSharedPtr gameRenderer)
{
	_gameRenderer = gameRenderer;

	_loadGameResources();
}

void GameAssetManager::_loadGameResources()
{
	_sprites = _loadSprite("sprites.json");
}

std::map<int, std::shared_ptr<Sprite>> GameAssetManager::_loadSprite(std::string fileName)
{
	int spriteId;
	int spriteWidth;
	int spriteHeight;
	std::string path;

	std::map<int, std::shared_ptr<Sprite>> spriteMap;
	try
	{
		std::ifstream spriteFile(fileName);
		json sprites;
		spriteFile >> sprites;

		for (auto& sprite : sprites.at("sprites"))
		{
			spriteId = sprite.at("id").get<int>();
			spriteWidth = sprite.at("width").get<int>();
			spriteHeight = sprite.at("height").get<int>();
			path = sprite.at("spriteSheetImage").get<std::string>();

			sdl2::TextureSharedPtr texture = sdl2::TextureSharedPtr(_loadTexture(path));
			std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(new Sprite(texture, spriteWidth, spriteHeight));
			spriteMap.insert(std::pair<int, std::shared_ptr<Sprite>>(spriteId, sprite));
		}
		return spriteMap;
	}
	catch (json::parse_error& e)
	{
		std::cout << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << std::endl;

		return spriteMap;
	}
}

sdl2::TextureSharedPtr GameAssetManager::_loadTexture(std::string path)
{
	sdl2::TextureSharedPtr loadedTexture;

	sdl2::SurfaceSharedPtr loadedSurface = sdl2::SurfaceSharedPtr(IMG_Load(path.c_str()));
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface.get(), SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0));
		loadedTexture = sdl2::TextureSharedPtr(SDL_CreateTextureFromSurface(_gameRenderer.get(), loadedSurface.get()));
		if (loadedTexture == NULL)
		{
			printf("Unable to create texture %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}
	return loadedTexture;
}

std::shared_ptr<Sprite> GameAssetManager::getSprite(int spriteId)
{
	std::map<int, std::shared_ptr<Sprite>>::iterator spriteIterator = _sprites.find(spriteId);
	if (spriteIterator != _sprites.end())
	{
		return spriteIterator->second;
	}
	return NULL;
}

