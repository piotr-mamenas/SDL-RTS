#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

using namespace std;

#include "nlohmann\json.hpp"

using json = nlohmann::json;

class GameObject
{
protected:
	int _id;
	int _spriteId;
	int _positionX;
	int _positionY;
	int _width;
	int _height;

	GameObject(int initialPositionX, int initialPositionY);
	GameObject(json json);
public:
	int getId();
	int getSpriteId();
	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
	virtual void deserializeFrom(json json) {};
};

#endif