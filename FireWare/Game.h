#ifndef _GAME_H_
#define _GAME_H_
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
class Time;
class SceneManger;
class SourceManager;
class WindowCreater;
class Game
{
public:
	Game();
	~Game();

	bool inite();
	void Update();

private:
	WindowCreater* m_pWindowCreater;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Event *m_pEvent;
	bool running;
	SceneManger* m_pSceneManger;
	Time *m_pTime;
	SourceManager* m_pSourceManager;

private:
	void Run();
};
#endif
