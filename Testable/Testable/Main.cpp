#include <iostream>
#include <SDL.h>

#include "BaseUnit.h"
#include "InfantryUnit.h"

using namespace std;

int main(int argc, char * argv[])
{
	InfantryUnit unit;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();

	}
	else
	{
		cout << "SDL initialization succeeded!";
	}

	cin.get();
	return 0;
}