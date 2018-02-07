#include "VirusBigExplosionControl.h"
#include "Transform.h"
#include "GameObject.h"
#include "SourceManager.h"
#include "Time.h"
#include "SpriteRederer.h"


VirusBigExplosionControl::VirusBigExplosionControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusBigExplosionControl")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pSpriteRender = static_cast<SpriteRederer*>(m_pSelfGameObject->GetComponent(k_spriteRenderer));
	m_pSelfGameObject->SetActive(false);
	m_timer = m_totalTime = 0.03;

}


VirusBigExplosionControl::~VirusBigExplosionControl()
{
	m_sprites.clear();
	m_pTransform = nullptr;
	m_pSpriteRender = nullptr;
}

void VirusBigExplosionControl::PlayAnimation(Vector2 positopn)
{
	m_index = 0;
	m_timer = m_totalTime;
	m_pSelfGameObject->SetActive(true);
	m_pTransform->SetPosition(positopn);
}

void VirusBigExplosionControl::Start()
{
	m_sprites.push_back(SourceManager::GetSprite("VirusBig_Explosion_01"));
	m_sprites.push_back(SourceManager::GetSprite("VirusBig_Explosion_02"));
	m_sprites.push_back(SourceManager::GetSprite("VirusBig_Explosion_03"));
	m_sprites.push_back(SourceManager::GetSprite("VirusBig_Explosion_04"));
	m_sprites.push_back(SourceManager::GetSprite("VirusBig_Explosion_05"));
}

void VirusBigExplosionControl::Update()
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


