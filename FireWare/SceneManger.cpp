#include "SceneManger.h"
#include "Scene.h"
#include "GamePlayingScene.h"



SceneManger* SceneManger::instance = nullptr;
Scene *SceneManger::m_curScene;

SceneManger::SceneManger()
{
	m_curScene = nullptr;
	m_pauseGame = false;
}


SceneManger::~SceneManger()
{
	GameEnd();
}


void SceneManger::Awake()
{
	if (!m_curScene) return;
	m_curScene->Awake();
}

void SceneManger::Start()
{
	if (!m_curScene) return;
	m_curScene->Start();
}

void SceneManger::GameUpdate()
{
	if (!m_curScene) return;
	m_curScene->Run();
}


void SceneManger::LoadScene(Scene* scene)
{
	DeleteScene();
	m_curScene = scene;
	Awake();
	Start();
}

SceneManger * SceneManger::getInstance()
{
	if (instance == nullptr)
	{
		instance = new SceneManger();
	}
	return instance;
}

void SceneManger::pause()
{
	Scene::SetPauseGame(true);
}

void SceneManger::play()
{
	Scene::SetPauseGame(false);
}


void SceneManger::DeleteScene()
{
	if (m_curScene)
	{
		delete 	m_curScene;
		m_curScene = nullptr;
	}
}

Scene * SceneManger::GetCurScene()
{
	return m_curScene;
}


void SceneManger::GameEnd()
{
	delete m_curScene;
	m_curScene = nullptr;
	instance = nullptr;
}
