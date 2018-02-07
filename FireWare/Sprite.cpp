#include "Sprite.h"
#include "WindowCreater.h"
#include <SDL_image.h>


Sprite::Sprite(const char* address)
{
	m_pRenderer = WindowCreater::GetInstance()->GetRenderer();
	m_pSurface = IMG_Load(address);
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pSurface);
}


Sprite::~Sprite()
{
	SDL_FreeSurface(m_pSurface);
	SDL_DestroyTexture(m_pTexture);
}
