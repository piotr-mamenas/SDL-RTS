#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <memory>

#include <SDL.h>
#include "SDLDeleter.h"

class Sprite
{
private:
	int _spriteSheetWidth;
	int _spriteSheetHeight;
	sdl2::TextureSharedPtr _spriteTexture;
	std::map<int,SDL_Rect> _clips;

public:
	Sprite(sdl2::TextureSharedPtr spriteTexture, int spriteWidth, int spriteHeight);
	sdl2::TextureSharedPtr getTexture();
	int getSpriteSheetWidth();
	int getSpriteSheetHeight();
	SDL_Rect getClip(int clipId);
};

#endif