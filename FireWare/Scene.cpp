#include "Scene.h"
#include "SceneManger.h"
#include "GameObject.h"
#include "SDL.h"


bool Scene::m_pausegame = false;

Scene::Scene(std::string name)
{
	m_name = name;
	m_pGameItems = new std::vector<GameObject*>();
}
Scene::~Scene()
{
	for (unsigned int i = 0; i < m_pGameItems->size(); ++i)
	{
		delete (*m_pGameItems)[i];
		(*m_pGameItems)[i] = nullptr;
	}
	delete m_pGameItems;
	m_pGameItems = nullptr;
}

void Scene::Awake()
{
	if (m_pGameItems->size() <= 0) return;
	for (auto go : *m_pGameItems)
	{
		go->Awake();
	}
}

void Scene::Start()
{
	if (m_pGameItems->size() <= 0) return;
	for (auto go : *m_pGameItems)
	{
		go->Start();
	}
}



void Scene::Run()
{
	if (m_pGameItems->size() <= 0) return;
	for (auto go : *m_pGameItems)
	{
		go->Update();
		go->Render();
	}
}


GameObject* Scene::findGameObject(std::string name)
{
	for (auto ob : *m_pGameItems)
	{
		if (ob->GetName() == name)
		{
			return ob;
		}
	}
	return nullptr;
}

void Scene::AddGameObject(GameObject *pGameObject)
{
	m_pGameItems->push_back(pGameObject);
}

void Scene::SetPauseGame(bool bpause)
{
	m_pausegame = bpause;
}

std::vector<GameObject*>* Scene::GetItems() const
{
	if(m_pGameItems != nullptr)
		return m_pGameItems;
	return nullptr;
}
