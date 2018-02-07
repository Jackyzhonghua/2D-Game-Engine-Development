#include "GameObject.h"
#include "SpriteRederer.h"
#include "Transform.h"
#include "Scene.h"
#include "GameBehavior.h"
#include <SDL.h>

GameObject::GameObject()
{
	m_PTransform = new Transform(this);
	m_pSpriteRenderer = nullptr;
	m_name = "";
	m_tag = "";
	m_pSelfScene = nullptr;
	m_bActive = true;
	m_bParentActive = true;
}

GameObject::GameObject(std::string name)
{
	m_PTransform = new Transform(this);
	m_name = name;
	m_tag = "";
	m_pSelfScene = nullptr;
	m_bActive = true;
}

GameObject::GameObject(std::string name,  Scene *const selfScene)
{
	m_PTransform = new Transform(this);
	m_name = name;
	m_tag = "";
	m_pSelfScene = selfScene;
	m_pSelfScene->AddGameObject(this);
	m_bActive = true;

}

GameObject::~GameObject()
{
	delete m_PTransform;
	m_PTransform = nullptr;
	for (auto cm : m_components)
	{
		delete cm;
		cm = nullptr;
	}
	m_components.clear();
	m_pSelfScene = nullptr;
}

void GameObject::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool GameObject::GetActive()
{
	return m_bActive;
}

void GameObject::AddComponent(Componentbehavior *com)
{
	if (com->GetType() == k_spriteRenderer)
	{
		m_pSpriteRenderer = static_cast<SpriteRederer*>(com);
		return;
	}
	m_components.push_back(com);
}

void GameObject::SetTransform(Transform *t)
{
	m_PTransform = t;
}

void GameObject::SetParent(GameObject * parent)
{
	m_PTransform->SetParent(static_cast<Transform*>(parent->GetComponent(k_transform)));
}


Componentbehavior *GameObject::GetComponent(std::string name)
{
	if (name == "Transform")
		return m_PTransform;
	if (name == "SpriteRederer")
		return m_pSpriteRenderer;
	for (auto c : m_components)
	{
		if (c->GetName() == name)
		{
			return  c;
		}
	}
	return nullptr;
}


Componentbehavior * GameObject::GetComponent(Components type)
{
	if (type == k_transform)
	{
		return m_PTransform;
	}
	if (type == k_spriteRenderer)
	{
		return m_pSpriteRenderer;
	}
		
	for (auto c : m_components)
	{
		if (c->GetType() == type)
		{
			return  c;
		}
	}
	return nullptr;
}

void GameObject::Awake()
{
	m_PTransform->Awake();
	for (auto c : m_components)
	{
		c->Awake();
	}
}

void GameObject::Start()
{
	m_PTransform->Start();
	for (auto c : m_components)
	{
		c->Start();
	}
}

void GameObject::Update()
{
	//check is parent active
	Transform *pParentTransform = m_PTransform->GetParent();
	if (pParentTransform)
	{
		GameObject *parentGameObject = pParentTransform->GetGameObject();
		if (!parentGameObject->GetActive())
		{
			m_bParentActive = false;
			return;
		}
		else
		{
			m_bParentActive = true;
		}
	}
	else
	{
		m_bParentActive = true;
	}
	//check is itself active
	if (!m_bActive) return;

	//update transform and every component
	m_PTransform->Update();
	for (auto c : m_components)
	{
		if (c->GetEnable())
		{
			c->Update();
		}
		if (c->GetType() == k_gameBehavior)
		{
			static_cast<GameBehavior*>(c)->UpdateTriggerCheck();
		}
	}
}

void GameObject::Render()
{
	if (!m_bParentActive)
	{
		return;
	}
	if (!m_bActive) return;
	if (m_pSpriteRenderer)
	{
		if (m_pSpriteRenderer->GetEnable())
			m_pSpriteRenderer->Update();
	}
}
