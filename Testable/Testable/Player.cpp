#include <iostream>
#include <list>
#include <string>

#include <SDL.h>

#include "Player.h"
#include "GameMap.h"

#define SCROLLBOX_SIZE_IN_PX 20
#define SCROLL_SPEED 3

enum SCROLLING_STATE {
	NO_SCROLLING = 0,
	SCROLLING_RIGHT = 1,
	SCROLLING_LEFT = 2,
	SCROLLING_UP = 3,
	SCROLLING_DOWN = 4
};

Player::Player(string color, list<BaseUnit*> startingUnits, unsigned int screenResolutionX, unsigned int screenResolutionY)
{
	_units = startingUnits;
	_color = color;
	_screenResolutionX = screenResolutionX;
	_screenResolutionY = screenResolutionY;
	_scrollingState = NO_SCROLLING;
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

void Player::scrollCamera()
{
	switch (_scrollingState) 
	{
	case SCROLLING_LEFT:
		_cameraX = _cameraX - SCROLL_SPEED;
		break;
	case SCROLLING_RIGHT:
		_cameraX = _cameraX + SCROLL_SPEED;
		break;
	case SCROLLING_UP:
		_cameraY = _cameraY + SCROLL_SPEED;
		break;
	case SCROLLING_DOWN:
		_cameraY = _cameraY - SCROLL_SPEED;
		break;
	}
}

void Player::_handleScrolling(int mousePositionX, int mousePositionY)
{
	_scrollingState = NO_SCROLLING;

	if (mousePositionX > _screenResolutionX - SCROLLBOX_SIZE_IN_PX 
		&& _cameraX < _gameMap->getMapWidth() - _screenResolutionX)
	{
		_scrollingState = SCROLLING_RIGHT;
	}

	if (mousePositionX < SCROLLBOX_SIZE_IN_PX && _cameraX > 0)
	{
		_scrollingState = SCROLLING_LEFT;
	}

	if (mousePositionY > _screenResolutionY - SCROLLBOX_SIZE_IN_PX &&
		_cameraY < _gameMap->getMapHeight() - _screenResolutionY)
	{
		_scrollingState = SCROLLING_UP;
	}

	if (mousePositionY < SCROLLBOX_SIZE_IN_PX && _cameraY > 0)
	{
		_scrollingState = SCROLLING_DOWN;
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