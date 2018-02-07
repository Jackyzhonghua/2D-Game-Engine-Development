#include "VirusMiddleHighLightControl.h"
#include "GameObject.h"
#include "SpriteRederer.h"
#include "Transform.h"
#include "Scene.h"
#include "Time.h"


VirusMiddleHighLightControl::VirusMiddleHighLightControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusMiddleHighLightControl")
{
	m_pSpriteRenderer = static_cast<SpriteRederer*>(m_pSelfGameObject->GetComponent(k_spriteRenderer));
	m_pTransform = m_pSelfGameObject->GetTransform();
	m_bGolower = true;
	m_changeSpeed = 1;
}


VirusMiddleHighLightControl::~VirusMiddleHighLightControl()
{
	m_pSpriteRenderer = nullptr;
	m_pTransform = nullptr;
}

void VirusMiddleHighLightControl::Start()
{
	m_pTransform->SetLocalPosition(0, 0);
}

void VirusMiddleHighLightControl::Update()
{
	AlphaControl();
}

void VirusMiddleHighLightControl::AlphaControl()
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
