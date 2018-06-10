#ifndef BASEUNIT_H
#define BASEUNIT_H

#include <string>

#include "Sprite.h"
#include "GameObject.h"

#include <nlohmann\json.hpp>

using json = nlohmann::json;

class Unit : public GameObject
{
protected:
	int _currentLife;
	int _damage;
	int _maxLife;
	std::unique_ptr<string> _unitName;

	bool _isAlive;
public:
	Unit(int initialPositionX, int initialPositionY, std::unique_ptr<Unit> unitTemplate);
	Unit(std::unique_ptr<json> unitJson);
	int getMaxLife();
	int getDamage();
	std::unique_ptr<string> getName();

	bool isAlive();
	void handleEvent(int clickPositionX, int clickPositionY, int eventType);
	void deserializeFrom(std::unique_ptr<json> json) override;
};
#endif