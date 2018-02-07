#include "VirusBigSideLightControl.h"
#include "GameObject.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "Time.h"


VirusBigSideLightControl::VirusBigSideLightControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusBigSideLightControl")
{
	m_pSpriteRenderer = static_cast<SpriteRederer*>(m_pSelfGameObject->GetComponent(k_spriteRenderer));
	m_pTransform = m_pSelfGameObject->GetTransform();
	m_bGolower = true;
	m_changeSpeed = 0.8;
}


VirusBigSideLightControl::~VirusBigSideLightControl()
{
	m_pTransform = nullptr;
}

void VirusBigSideLightControl::Start()
{
	m_pTransform->SetLocalPosition(0, 0);
}

void VirusBigSideLightControl::Update()
{
	AlphaControl();
}

void VirusBigSideLightControl::AlphaControl()
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
