#ifndef GAMESCENARIO_H
#define GAMESCENARIO_H

#include <vector>
#include <memory>

#include "Player.h"
#include "GameMap.h"

class GameScenario
{
private:
	std::vector<std::shared_ptr<Player>> _players;
	std::shared_ptr<GameMap> _gameMap;

public:
	GameScenario();

};

#endif