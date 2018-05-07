#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

class Sprite
{
private:
	unsigned int _width;
	unsigned int _height;
	SDL_Texture* _spriteTexture;
public:
	Sprite(SDL_Texture* spriteTexture);
	SDL_Texture* getTexture();

	unsigned int getWidth();
	unsigned int getHeight();
};

#endif