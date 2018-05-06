#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

class Sprite
{
private:
	int _width;
	int _height;
	SDL_Texture* _spriteTexture;
public:
	Sprite(SDL_Texture* spriteTexture);
	SDL_Texture* getTexture();
};

#endif