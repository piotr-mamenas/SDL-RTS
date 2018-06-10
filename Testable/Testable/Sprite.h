#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <memory>

#include <SDL.h>

class Sprite
{
private:
	int _spriteSheetWidth;
	int _spriteSheetHeight;
	std::shared_ptr<SDL_Texture> _spriteTexture;
	std::map<int,std::unique_ptr<SDL_Rect>> _clips;

public:
	Sprite(std::shared_ptr<SDL_Texture> spriteTexture, int spriteWidth, int spriteHeight);
	std::unique_ptr<SDL_Texture> getTexture();
	int getSpriteSheetWidth();
	int getSpriteSheetHeight();
	std::unique_ptr<SDL_Rect> getClip(int clipId);
};

#endif