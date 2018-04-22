#include "Sprite.h"

#include <SDL.h>

Sprite::Sprite(SDL_Surface* sprite)
{
	_spriteImage = sprite;
}

SDL_Surface* Sprite::_getImage()
{
	return _spriteImage;
}