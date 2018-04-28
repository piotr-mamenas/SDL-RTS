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
	unsigned id;
	string path;

	map<unsigned int, SDL_Surface*> units;
	ifstream infile("unit_images.dat");

	while (infile >> id >> path) 
	{
		SDL_Surface* optimizedSurface = _loadSurface(path);
		units.insert(pair<unsigned int, SDL_Surface*>(id, optimizedSurface));
	}
	_units = units;
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
	std::map<unsigned int, SDL_Surface*>::iterator unitIterator;
	for(unitIterator = _units.begin(); unitIterator != _units.end(); unitIterator++)
	{
		SDL_FreeSurface(unitIterator -> second);
	}
}

SDL_Surface* GameAssetManager::getUnitImage(int unitId)
{
	map<unsigned int , SDL_Surface*>::iterator unitIterator = _units.find(unitId);
	if (unitIterator != _units.end()) 
	{
		return unitIterator -> second;
	}
	return NULL;
}