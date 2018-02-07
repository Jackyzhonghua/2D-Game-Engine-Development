#include "Componentbehavior.h"
#include "GameObject.h"
#include "Collider.h"
#include "CheckCollider.h"



Componentbehavior::Componentbehavior(GameObject *gameobject, std::string  name, Components type)
{
	m_pSelfGameObject = gameobject;
	m_name = name;
	m_type = type;
	m_bEnable = true;

}

Componentbehavior::Componentbehavior()
{
	m_pSelfGameObject = nullptr;
	m_name = "";
	m_bEnable = true;

}

Componentbehavior::~Componentbehavior()
{
	m_pSelfGameObject = nullptr;
}

void Componentbehavior::Update()
{
	
}

void Componentbehavior::SetEnable(bool bEnable)
{
	m_bEnable = bEnable;
}



bool Componentbehavior::GetEnable()
{
	return m_bEnable;
}

