#include "Sprite.h"

#include <SDL.h>

Sprite::Sprite(SDL_Texture* spriteTexture)
{
	_spriteTexture = spriteTexture;
}

SDL_Texture* Sprite::getTexture()
{
	return _spriteTexture;
}

unsigned int Sprite::getWidth()
{
	return _width;
}

unsigned int Sprite::getHeight()
{
	return _height;
}