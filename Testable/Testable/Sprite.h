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
	std::map<int,std::unique_ptr<SDL_Rect>> _clips;

public:
	Sprite(sdl2::TextureSharedPtr spriteTexture, int spriteWidth, int spriteHeight);
	sdl2::TexturePtr getTexture();
	int getSpriteSheetWidth();
	int getSpriteSheetHeight();
	std::unique_ptr<SDL_Rect> getClip(int clipId);
};

#endif