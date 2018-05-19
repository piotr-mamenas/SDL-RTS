#include "GameObject.h"

GameObject::GameObject(int spriteId, int initialPositionX, int initialPositionY)
{
	_spriteId = spriteId;
	_positionX = initialPositionX;
	_positionY = initialPositionY;
}

int GameObject::getPositionX()
{
	return _positionX;
}

int GameObject::getPositionY()
{
	return _positionY;
}

int GameObject::getWidth()
{
	return _width;
}

int GameObject::getHeight()
{
	return _height;
}

int GameObject::getSpriteId()
{
	return _spriteId;
}