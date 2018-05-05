#ifndef GAMESCENARIO_H
#define GAMESCENARIO_H

#include <iostream>
#include <list>

#include "Player.h"
#include "GameMap.h"

using namespace std;

class GameScenario
{
private:
	list<Player*> _players;
	GameMap* _gameMap;

public:
	GameScenario();

};

#endif