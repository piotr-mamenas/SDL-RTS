#include "Sprite.h"

#include <SDL.h>

Sprite::Sprite(SDL_Surface* spriteImage)
{
	_spriteImage = spriteImage;
}

SDL_Surface* Sprite::getImage()
{
	return _spriteImage;
}