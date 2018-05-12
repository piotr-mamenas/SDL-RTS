#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "Player.h"
#include "GameMap.h"

#define SCROLLBOX_SIZE_IN_PX 30
#define SCROLL_SPEED 8

Player::Player(string color, list<BaseUnit*> startingUnits, int screenResolutionX, int screenResolutionY)
{
	_units = startingUnits;
	_color = color;
	_screenResolutionX = screenResolutionX;
	_screenResolutionY = screenResolutionY;
}

Player::Player(string color, int screenResolutionX, int screenResolutionY)
{
	_color = color;
	_screenResolutionX;
	_screenResolutionY;
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

void Player::setCamera(int cameraX, int cameraY)
{
	_cameraX = cameraX;
	_cameraY = cameraY;
}

int Player::getCameraX()
{
	return _cameraX;
}

int Player::getCameraY()
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

void Player::setPlayerHostile(Player* player)
{
	bool isPlayerAlreadyHostile = find(_hostilePlayers.begin(), _hostilePlayers.end(), player) != _hostilePlayers.end();

	if (!isPlayerAlreadyHostile)
	{
		_hostilePlayers.push_back(player);
	}
}