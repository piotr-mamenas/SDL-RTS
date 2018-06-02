#ifndef BASEUNIT_H
#define BASEUNIT_H

#include <string>

#include "Sprite.h"
#include "GameObject.h"

#include <nlohmann\json.hpp>

using namespace std;
using json = nlohmann::json;

class Unit : public GameObject
{
protected:
	int _currentLife;
	int _damage;
	int _maxLife;
	string _unitName;

	bool _isAlive;
public:
	Unit(int initialPositionX, int initialPositionY, Unit* unitTemplate);
	Unit(json unitJson);
	int getMaxLife();
	int getDamage();
	string getName();

	bool isAlive();
	void handleEvent(int clickPositionX, int clickPositionY, int eventType);
	void deserializeFrom(json json) override;
};
#endif