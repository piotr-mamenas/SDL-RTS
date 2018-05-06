#include "GameObject.h"

GameObject::GameObject(unsigned int initialPositionX, unsigned int initialPositionY)
{
	_positionX = initialPositionX;
	_positionY = initialPositionY;
}

unsigned int GameObject::getPositionX()
{
	return _positionX;
}

unsigned int GameObject::getPositionY()
{
	return _positionY;
}

unsigned int GameObject::getId() 
{
	return _id;
}