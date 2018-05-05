#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

using namespace std;

class GameObject
{
protected:
	unsigned int _id;
	unsigned int _positionX;
	unsigned int _positionY;
	unsigned int _width;
	unsigned int _height;

	GameObject(unsigned int initialPositionX, unsigned int initialPositionY);
public:
	unsigned int getId();
	unsigned int getPositionX();
	unsigned int getPositionY();
};

#endif