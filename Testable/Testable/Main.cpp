#include <iostream>
#include <SDL.h>

#include "BaseUnit.h"
#include "InfantryUnit.h"
#include "GameContext.h"

using namespace std;

int main(int argc, char * argv[])
{
	bool isMinimized = true;
	GameContext* context = new GameContext(640,480,isMinimized);
	
	bool isGameInitialized = context -> init(true);
	if (!isGameInitialized) 
	{
		printf("Failed to initialize Game Engine!\n");
	}
	context->close();

	return 0;
}