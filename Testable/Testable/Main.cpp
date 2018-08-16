#include <iostream>
#include <memory>

#include <SDL.h>

#include "GameContext.h"

using namespace std;

int main(int argc, char * argv[])
{
	bool isWindowMode = true;
	std::shared_ptr<GameContext> context = std::make_shared<GameContext>(new GameContext(640,480,isWindowMode));
	
	bool isGameInitialized = context -> init();
	if (!isGameInitialized) 
	{
		printf("Failed to initialize Game Engine!\n");
	}
	context -> close();

	return 0;
}