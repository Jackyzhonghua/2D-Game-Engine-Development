#include "BulletControl.h"
#include "Transform.h"
#include "GameObject.h"
#include "Time.h"
#include "Time.h"
#include "Collider.h"
#include "VirusBasControl.h"
#include "AudioEffect.h"



BulletControl::BulletControl(GameObject *pGameobject) : GameBehavior(pGameobject, "BulletControl")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pAudioEffect = static_cast<AudioEffect*>(m_pSelfGameObject->GetComponent(k_audioEffect));
	m_bRun = false;
	m_moveSpeed = 600;
	
}


BulletControl::~BulletControl()
{
	m_pTransform = nullptr;
}

void BulletControl::SetRun(bool bRun)
{
	m_bRun = bRun;
}

void BulletControl::Dead()
{
	m_pTransform->GetGameObject()->SetActive(false);
	m_bRun = false;
}

void BulletControl::WakeUp()
{
	m_pTransform->GetGameObject()->SetActive(true);
	m_bRun = true;
}

void BulletControl::Start()
{
	m_pSelfGameObject->SetActive(false);
}

void BulletControl::Update()
{
	Move();
}

void BulletControl::OntriggerEnter(Collider & other)
{
	if (other.GetGameObject()->GetTag() == "Enemy")
	{
		Dead();
		if (other.GetGameObject()->GetName() == "VirusSmall")
		{
			static_cast<VirusBasControl*>(other.GetGameObject()->GetComponent("VirusSmallControl"))->GetDamage(1);
		}
		if (other.GetGameObject()->GetName() == "VirusMiddle")
		{
			static_cast<VirusBasControl*>(other.GetGameObject()->GetComponent("VirusMiddleControl"))->GetDamage(1);
		}
		if (other.GetGameObject()->GetName() == "VirusBig")
		{
			static_cast<VirusBasControl*>(other.GetGameObject()->GetComponent("VirusBigControl"))->GetDamage(1);
		}
		m_pAudioEffect->Play();
	}
}

void BulletControl::Move()
{
	if (m_bRun)
	{
		m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() - m_moveSpeed*Time::DeltaTime());
		if (m_pTransform->GetPosition().Y() < 0)
		{
			Dead();
		}
	}
}
