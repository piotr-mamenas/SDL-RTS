#include <iostream>
#include <list>
#include <string>

#include <SDL.h>

#include "Player.h"
#include "GameMap.h"

#define SCROLLBOX_SIZE_IN_PX 20
#define SCROLL_SPEED 3

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

void Player::scrollCamera()
{
	if (_scrollingUp)
	{
		_cameraY = _cameraY + SCROLL_SPEED;
	}

	if (_scrollingDown)
	{
		_cameraY = _cameraY - SCROLL_SPEED;
	}

	if (_scrollingLeft)
	{
		_cameraX = _cameraX - SCROLL_SPEED;
	}

	if (_scrollingRight)
	{
		_cameraX = _cameraX + SCROLL_SPEED;
	}

	_handleScrolling(_mousePositionX, _mousePositionY);
}

void Player::_resetScrolling()
{
	_scrollingLeft = false;
	_scrollingRight = false;
	_scrollingUp = false;
	_scrollingDown = false;
}

void Player::_handleScrolling(int mousePositionX, int mousePositionY)
{
	_resetScrolling();

	if (mousePositionX > _screenResolutionX - SCROLLBOX_SIZE_IN_PX 
		&& _cameraX < _gameMap->getMapWidth() - _screenResolutionX)
	{
		_scrollingRight = true;
	}

	if (mousePositionX < SCROLLBOX_SIZE_IN_PX && _cameraX > 0)
	{
		_scrollingLeft = true;
	}

	if (mousePositionY > _screenResolutionY - SCROLLBOX_SIZE_IN_PX &&
		_cameraY < _gameMap->getMapHeight() - _screenResolutionY)
	{
		_scrollingUp = true;
	}

	if (mousePositionY < SCROLLBOX_SIZE_IN_PX && _cameraY > 0)
	{
		_scrollingDown = true;
	}
}

void Player::handleInteraction(SDL_Event e, list<BaseUnit*> units)
{
	SDL_GetMouseState(&_mousePositionX, &_mousePositionY);

	if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		for (BaseUnit* unit : units)
		{
			unit->handleEvent(_mousePositionX, _mousePositionY, e.type);
		}
	}
}