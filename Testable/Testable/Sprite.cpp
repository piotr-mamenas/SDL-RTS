#include "Sprite.h"

#include <SDL.h>

Sprite::Sprite(SDL_Surface* sprite)
{
	_spriteImage = sprite;
}

SDL_Surface* Sprite::getImage()
{
	return _spriteImage;
}