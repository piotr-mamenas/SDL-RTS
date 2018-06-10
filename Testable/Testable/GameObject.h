#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>

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
	GameObject(std::unique_ptr<json> json);
public:
	int getId();
	int getSpriteId();
	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
	virtual void deserializeFrom(std::unique_ptr<json> json) {};
};

#endif