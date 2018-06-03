#include "GameObject.h"

using json = nlohmann::json;

GameObject::GameObject(int initialPositionX, int initialPositionY)
{
	_positionX = initialPositionX;
	_positionY = initialPositionY;
}

GameObject::GameObject(json json)
{
}

int GameObject::getId()
{
	return _id;
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