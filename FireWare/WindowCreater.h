#ifndef _WINDOW_CREATER_H_
#define _WINDOW_CREATER_H_
#include <SDL.h>
class WindowCreater
{
public:
	~WindowCreater();
	
	static WindowCreater* GetInstance();
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
private:
	int windowWidth;
	int windowHeight;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	static WindowCreater* m_pInstance;
private:
	WindowCreater();
};
#endif