#ifndef GAMESCENARIO_H
#define GAMESCENARIO_H

#include <vector>
#include <memory>

#include "Player.h"
#include "GameMap.h"

class GameScenario
{
private:
	std::vector<std::unique_ptr<Player>> _players;
	std::unique_ptr<GameMap> _gameMap;

public:
	GameScenario();

};

#endif