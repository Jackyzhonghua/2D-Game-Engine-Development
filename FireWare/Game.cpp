#include "Game.h"
#include "WindowCreater.h"
#include "SceneManger.h"
#include "Input.h"
#include "Time.h"
#include "SourceManager.h"
#include "GameManagerControl.h"
#include "GamePlayingScene.h"


Game::Game()
{
	m_pWindow = nullptr;
	m_pRenderer = nullptr;
	m_pEvent = nullptr;
	m_pTime = nullptr;
	m_pSceneManger = nullptr;
	m_pWindowCreater = nullptr;
}


Game::~Game()
{
	delete m_pSourceManager;
	delete m_pSceneManger;
	delete m_pEvent;
	delete m_pTime;
	delete m_pWindowCreater;
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Game::inite()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	TTF_Init();
	m_pWindowCreater = WindowCreater::GetInstance();
	m_pWindow = m_pWindowCreater->GetWindow();
	if (!m_pWindow)
	{
		SDL_Log("Faild to create windows:%s", SDL_GetError());
		return false;
	}
	m_pRenderer = m_pWindowCreater->GetRenderer();
	if (!m_pRenderer)
	{
		SDL_Log("Faild to create renderer:%s", SDL_GetError());
		return false;
	}
	if (Mix_Init(MIX_INIT_OGG) < 0)
	{
		SDL_Log("Faild to init SDL_mixer:%s", Mix_GetError());
		return false;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
	{
		SDL_Log("Failed to open audio:%s", Mix_GetError());
		return false;
	}
	running = true;

	m_pEvent= Input::GetInstance();
	m_pTime = Time::GetInstance();
	m_pSceneManger= SceneManger::getInstance();
	SceneManger::LoadScene(new GamePlayingScene());
	m_pSourceManager = SourceManager::GetInstance();

	m_pTime->PauseGame();
	return true;
}



void Game::Update()
{
	while (running)
	{
		m_pTime->Update();
		while (SDL_PollEvent(*&m_pEvent))
		{
			if (m_pEvent->type == SDL_WINDOWEVENT)
			{
				if (m_pEvent->window.event == SDL_WINDOWEVENT_CLOSE)
				{
					//exit when window is closed
					running = false;
				}
			}
			if (m_pEvent->type == SDL_KEYDOWN)
			{
				if (m_pEvent->key.keysym.sym == SDLK_SPACE)
				{
					if (GameManagerControl::GetbFinishGame())
					{
						SceneManger::LoadScene(new GamePlayingScene());
						m_pTime->PauseGame();
						GameManagerControl::SetBStartGame(false);
						GameManagerControl::SetBFinishGame(false);
					}
					else
					{
						m_pTime->RunGame();
						GameManagerControl::SetBStartGame(true);
					}
				}
			}
		}
		Run();
	}
}

void Game::Run()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_pRenderer);
	m_pSceneManger->GameUpdate();
	SDL_RenderPresent(m_pRenderer);
}