#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

using namespace std;

class GameObject
{
protected:
	int _spriteId;
	int _positionX;
	int _positionY;
	int _width;
	int _height;

	GameObject(int spriteId, int initialPositionX, int initialPositionY);
public:
	int getSpriteId();
	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
};

#endif