#include "LeukocyteLightControl.h"
#include "GameObject.h"
#include "SpriteRederer.h"
#include "Transform.h"
#include "Scene.h"
#include "Time.h"



LeukocyteLightControl::LeukocyteLightControl(GameObject *pGameobject) : GameBehavior(pGameobject, "LeukocyteLightControl")
{
	m_pSpriteRenderer = static_cast<SpriteRederer*>(m_pSelfGameObject->GetComponent(k_spriteRenderer));
	m_pTransform = m_pSelfGameObject->GetTransform();
	m_bGolower = true;
	m_changeSpeed = 2;
}


LeukocyteLightControl::~LeukocyteLightControl()
{
	m_pSpriteRenderer = nullptr;
	m_pTransform = nullptr;
}
   
void LeukocyteLightControl::Start()
{
	//set parent and local position
	GameObject *pParent = m_pSelfGameObject->GetSelfScene()->findGameObject("Leukocyte");
	m_pTransform->SetParent(pParent->GetTransform());
	std::string name = m_pTransform->GetParent()->GetGameObject()->GetName();
	m_pTransform->SetLocalPosition(0, 0);
}

void LeukocyteLightControl::Update()
{
	AlphaControl();
}

void LeukocyteLightControl::AlphaControl()
{
	if (m_bGolower)
	{
		m_pSpriteRenderer->SetAlpha(m_pSpriteRenderer->GetAlpha() - m_changeSpeed * Time::DeltaTime());
		if (m_pSpriteRenderer->GetAlpha() < 0.001)
			m_bGolower = false;
	}
	else
	{
		m_pSpriteRenderer->SetAlpha(m_pSpriteRenderer->GetAlpha() + m_changeSpeed * Time::DeltaTime());
		if (m_pSpriteRenderer->GetAlpha() > 0.990)
			m_bGolower = true;
	}
}
