#ifndef SPRITE_H
#define SPRITE_H

#include <map>

#include <SDL.h>

using namespace std;

class Sprite
{
private:
	int _spriteSheetWidth;
	int _spriteSheetHeight;
	SDL_Texture* _spriteTexture;
	map<int,SDL_Rect> _clips;

public:
	Sprite(SDL_Texture* spriteTexture, int spriteWidth, int spriteHeight);
	SDL_Texture* getTexture();
	int getSpriteSheetWidth();
	int getSpriteSheetHeight();
	SDL_Rect* getClip(int clipId);
};

#endif