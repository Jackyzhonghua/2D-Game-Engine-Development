#include "VirusSmallExplosionControl.h"
#include "Transform.h"
#include "GameObject.h"
#include "SourceManager.h"
#include "Time.h"
#include "SpriteRederer.h"


VirusSmallExplosionControl::VirusSmallExplosionControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusSmallExplosionControl")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pSpriteRender = static_cast<SpriteRederer*>(m_pSelfGameObject->GetComponent(k_spriteRenderer));
	m_pSelfGameObject->SetActive(false);
	m_timer = m_totalTime = 0.03;

}


VirusSmallExplosionControl::~VirusSmallExplosionControl()
{
	m_sprites.clear();
	m_pTransform = nullptr;
	m_pSpriteRender = nullptr;
}

void VirusSmallExplosionControl::PlayAnimation(Vector2 positopn)
{
	m_index = 0;
	m_timer = m_totalTime;
	m_pSelfGameObject->SetActive(true);
	m_pTransform->SetPosition(positopn);
}

void VirusSmallExplosionControl::Start()
{
	m_sprites.push_back(SourceManager::GetSprite("VirusSmall_Explosion_01"));
	m_sprites.push_back(SourceManager::GetSprite("VirusSmall_Explosion_02"));
	m_sprites.push_back(SourceManager::GetSprite("VirusSmall_Explosion_03"));
	m_sprites.push_back(SourceManager::GetSprite("VirusSmall_Explosion_04"));
}

void VirusSmallExplosionControl::Update()
{
	m_timer -= Time::GetInstance()->DeltaTime();
	if (m_timer <= 0)
	{
		if (m_index == m_sprites.size())
		{
			m_index = 0;
			m_pSelfGameObject->SetActive(false);
			return;
		}
		m_pSpriteRender->SetSprite(m_sprites[m_index]);
	
		m_timer = m_totalTime;
		++m_index;
	}
}


