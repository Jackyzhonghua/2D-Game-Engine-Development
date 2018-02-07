#ifndef _SPRITE_H_
#define _SPRITE_H_
#include  <SDL.h>
#include <iostream>
#include <string.h>


class Sprite
{
public:
	Sprite(const char* address);
	~Sprite();
	SDL_Surface *GetSurface()const { return m_pSurface; }
	SDL_Texture *GetTexture() const { return m_pTexture; }
private:
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurface;
	SDL_Texture* m_pTexture;
};
#endif 
