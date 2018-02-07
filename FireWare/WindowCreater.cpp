#include "WindowCreater.h"
WindowCreater* WindowCreater::m_pInstance = nullptr;

WindowCreater::WindowCreater()
{
	windowWidth = 700;
	windowHeight = 1000;
	m_pWindow = nullptr;
	m_pRenderer = nullptr;
	m_pWindow = SDL_CreateWindow("paint demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
}


WindowCreater::~WindowCreater()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
}



WindowCreater * WindowCreater::GetInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new WindowCreater();
	}
	return m_pInstance;
}

SDL_Window* WindowCreater::GetWindow()
{
	return m_pWindow;
}
SDL_Renderer* WindowCreater::GetRenderer()
{
	return m_pRenderer;
}


