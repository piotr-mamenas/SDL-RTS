#include <map>
#include <exception>
#include <iostream>

#include "Sprite.h"

#include <SDL.h>

Sprite::Sprite(sdl2::TextureSharedPtr spriteTexture, int spriteWidth, int spriteHeight)
{
	int clipCounter = 0;
	_spriteTexture = spriteTexture;

	SDL_QueryTexture(_spriteTexture.get(), NULL, NULL, &_spriteSheetWidth, &_spriteSheetHeight);
	
	if (_spriteSheetWidth % spriteWidth != 0)
	{
		throw std::invalid_argument("Loaded SpriteSheet Width is not divisable by Sprite Width");
	}

	if (_spriteSheetHeight % spriteHeight != 0)
	{
		throw std::invalid_argument("Loaded SpriteSheet Height is not divisable by Sprite Height");
	}

	for (int cntY = 0; cntY < (_spriteSheetHeight / spriteHeight); cntY++)
	{
		for (int cntX = 0; cntX < (_spriteSheetWidth / spriteWidth); cntX++)
		{
			clipCounter++;

			SDL_Rect spriteClip;
			spriteClip.w = spriteWidth;
			spriteClip.h = spriteHeight;
			spriteClip.x = cntX * spriteWidth;
			spriteClip.y = cntY * spriteHeight;

			_clips.insert(std::pair<int, SDL_Rect>(clipCounter, spriteClip));
		}
	}
}

sdl2::TextureSharedPtr Sprite::getTexture()
{
	return _spriteTexture;
}

int Sprite::getSpriteSheetWidth()
{
	return _spriteSheetWidth;
}

int Sprite::getSpriteSheetHeight()
{
	return _spriteSheetHeight;
}

SDL_Rect Sprite::getClip(int clipId)
{
	std::map<int, SDL_Rect>::iterator clipIterator = _clips.find(clipId);
	if (clipIterator != _clips.end())
	{
		return clipIterator->second;
	}
}