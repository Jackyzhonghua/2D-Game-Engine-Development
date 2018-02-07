#include "CannonballControl.h"
#include "SourceManager.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "SpriteRederer.h"
#include "Mathf.h"
#include "Scene.h"
#include "VirusManagerControl.h"
#include "AudioEffect.h"



CannonballControl::CannonballControl(GameObject *pGameobject) : GameBehavior(pGameobject, "CannonballControl")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pSpriteRender = static_cast<SpriteRederer*>(m_pSelfGameObject->GetComponent(k_spriteRenderer));
	m_pAudioEffect = static_cast<AudioEffect*>(m_pSelfGameObject->GetComponent(k_audioEffect));

	m_pSelfGameObject->SetActive(false);
	m_bExplode = false;
	m_timer = m_totalTime = 0.03;
	m_changeSpeed = 0;
	m_moveSpeed = 0;
}


CannonballControl::~CannonballControl()
{

}

void CannonballControl::Start()
{
	m_sprites.push_back(SourceManager::GetSprite("cannonball_01"));
	m_sprites.push_back(SourceManager::GetSprite("cannonball_02"));
	m_sprites.push_back(SourceManager::GetSprite("cannonball_03"));
	m_sprites.push_back(SourceManager::GetSprite("cannonball_04"));
	m_sprites.push_back(SourceManager::GetSprite("cannonball_05"));
	m_pVirusManagerControl = static_cast<VirusManagerControl*>(m_pSelfGameObject->GetSelfScene()->findGameObject("VirusManager")->GetComponent("VirusManagerControl"));
}

void CannonballControl::Update()
{
	if (m_bExplode)
	{
		m_timer -= Time::DeltaTime();
		if (m_timer <= 0)
		{
			if (m_index == m_sprites.size())
			{
				m_index = m_sprites.size()-1;
			}
			m_pSpriteRender->SetSprite(m_sprites[m_index]);

			m_timer = m_totalTime;
			++m_index;
		}
		m_pTransform->SetScale(m_pTransform->GetScale().X() + m_changeSpeed * Time::DeltaTime(), m_pTransform->GetScale().Y() + m_changeSpeed * Time::DeltaTime());
		if (m_pTransform->GetScale().X() > 50)
		{
			m_pVirusManagerControl->GetExplosion();
			m_pSelfGameObject->SetActive(false);
		}
	}
	else
	{
		if (m_pTransform->GetPosition().Y() > 500)
		{
			m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() -m_moveSpeed * Time::DeltaTime());
		}
		else
		{
			m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() + m_moveSpeed * Time::DeltaTime());
		}

		if (Mathf::Abs(m_pTransform->GetPosition().Y() - 500) < 20)
		{
			m_bExplode = true;
			m_pAudioEffect->Play();
		}
	}
}

void CannonballControl::PlayAnimation(Vector2 positopn)
{
	m_bExplode = false;
	m_timer = m_totalTime;
	m_changeSpeed = 300;
	m_moveSpeed = 1200;
	m_index = 0;
	m_pSelfGameObject->SetActive(true);
	m_pTransform->SetScale(1, 1);
	m_pTransform->SetPosition(positopn);
}
