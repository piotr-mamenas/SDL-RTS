#include <iostream>
#include <list>
#include <string>

#include <SDL.h>

#include "Player.h"
#include "GameMap.h"

#define SCROLLBOX_SIZE_IN_PX 10

Player::Player(string color, list<BaseUnit*> startingUnits, unsigned int screenResolutionX, unsigned int screenResolutionY)
{
	_units = startingUnits;
	_color = color;
	_screenResolutionX = screenResolutionX;
	_screenResolutionY = screenResolutionY;
}

void Player::addUnit(BaseUnit* unit)
{
	_units.push_back(unit);
}

list<BaseUnit*> Player::getUnits()
{
	return _units;
}

void Player::startNewGame(GameMap* gameMap)
{
	_gameMap = gameMap;
}

void Player::setCamera(unsigned int cameraX, unsigned int cameraY)
{
	_cameraX = cameraX;
	_cameraY = cameraY;
}

unsigned int Player::getCameraX()
{
	return _cameraX;
}

unsigned int Player::getCameraY()
{
	return _cameraY;
}

void Player::_handleScrolling(int mousePositionX, int mousePositionY)
{
	if (mousePositionX > _screenResolutionX - SCROLLBOX_SIZE_IN_PX &&
		_cameraX < _gameMap->getMapWidth() - _screenResolutionX)
	{
		_cameraX++;
	}
	if (mousePositionX > SCROLLBOX_SIZE_IN_PX && _cameraX > 0)
	{
		_cameraX--;
	}

	// Mouse - RIGHT
	if (mousePositionY > _screenResolutionY - SCROLLBOX_SIZE_IN_PX &&
		_cameraY < _gameMap->getMapHeight() - _screenResolutionY)
	{
		_cameraY++;
	}

	if (mousePositionY < SCROLLBOX_SIZE_IN_PX && _cameraY > 0)
	{
		_cameraY--;
	}
}

void Player::handleInteraction(SDL_Event e, list<BaseUnit*> units)
{
	int mousePositionX = 0;
	int mousePositionY = 0;
	SDL_GetMouseState(&mousePositionX, &mousePositionY);

	_handleScrolling(mousePositionX, mousePositionY);

	if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		for (BaseUnit* unit : units)
		{
			unit->handleEvent(mousePositionX, mousePositionY, e.type);
		}
	}
}