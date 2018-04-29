#include "BaseUnit.h"

#include <iostream>

BaseUnit::BaseUnit(unsigned int initialPositionX, unsigned int initialPositionY) 
{
	_mapPositionX = initialPositionX;
	_mapPositionY = initialPositionY;
}

unsigned int BaseUnit::getPositionX()
{
	return _mapPositionX;
}

unsigned int BaseUnit::getPositionY() 
{
	return _mapPositionY;
}

unsigned int BaseUnit::getId()
{
	return _id;
}

void BaseUnit::handleEvent(SDL_Event* e)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		bool mouseInside = false;
		SDL_GetMouseState(&x, &y);

		if (x < _mapPositionX || 
			x > _mapPositionX + _unitWidth ||
			y < _mapPositionY ||
			y > _mapPositionY + _unitHeight)
		{
			mouseInside = false;
		}

		if (mouseInside)
		{
			switch (e -> type)
			{
			case SDL_MOUSEMOTION:
				printf("Mouse Over Unit: %d\n", _id);
				break;
			case SDL_MOUSEBUTTONDOWN:
				printf("Mouse Down Unit: %d\n", _id);
				break;
			case SDL_MOUSEBUTTONUP:
				printf("Mouse Up Unit: %d\n", _id);
				break;
			}
		}
	}
}