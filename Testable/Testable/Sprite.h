#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

class Sprite
{
private:
	int _width;
	int _height;
	SDL_Surface* _spriteImage;
public:
	Sprite(SDL_Surface* spriteImage);
	SDL_Surface* getImage();
};

#endif