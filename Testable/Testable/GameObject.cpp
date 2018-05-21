#include "GameObject.h"

using json = nlohmann::json;

GameObject::GameObject(int objectId, int initialPositionX, int initialPositionY)
{
	_id = objectId;
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