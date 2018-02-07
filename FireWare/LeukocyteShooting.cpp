#include "LeukocyteShooting.h"
#include "GameObject.h"
#include "Input.h"
#include "Time.h"
#include "Transform.h"
#include "Bullet.h"
#include "BulletControl.h"
#include "Cannonball.h"
#include "CannonballControl.h"
#include "AudioEffect.h"
#include "Scene.h"
#include "TextMesh.h"
#include "Collider.h"
#include "CannonBallGiftControl.h"



LeukocyteShooting::LeukocyteShooting(GameObject *pGameobject) : GameBehavior(pGameobject, "LeukocyteShooting")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pAudioEffect=static_cast<AudioEffect*>(m_pSelfGameObject->GetComponent(k_audioEffect));
	for (int i = 0; i < 60; ++i)
	{
		Bullet *pBullet = new Bullet(this->GetGameObject()->GetSelfScene());
		m_vBullets.push_back(pBullet);
		if (i < 5)
		{
			Cannonball *pCannonball = new Cannonball(this->GetGameObject()->GetSelfScene());
			m_vCannonballs.push_back(pCannonball);
		}
	}
	m_timer = m_totalTime = 0.2;
	m_cannonTimer = m_totalCannonTime = 1;
	m_bShootCannon = false;
	m_numCannon = 2;
}


LeukocyteShooting::~LeukocyteShooting()
{
	m_pTransform = nullptr;
	for (auto vb : m_vBullets)
	{
		vb = nullptr;
	}
}

void LeukocyteShooting::Awake()
{
	m_pAudioEffect->SetVolume(0.5);
	pCannonBallNumTextMesh = static_cast<TextMesh*>( m_pSelfGameObject->GetSelfScene()->findGameObject("CannonBallNumText")->GetComponent(k_textMesh));
	ShowNumCannon();
}

void LeukocyteShooting::AddCannon(int num)
{
	m_numCannon += num;
	ShowNumCannon();
}

void LeukocyteShooting::Update()
{
	Shoot();
	if (Input::GetButtonDown(Space))
	{
		if (m_bShootCannon && m_numCannon > 0)
		{
			m_numCannon -= 1;
			ShowNumCannon();
			ShootCannonball();
			m_bShootCannon = false;
			m_cannonTimer = m_totalCannonTime;
		}
	}

	if (!m_bShootCannon)
	{
		m_cannonTimer -= Time::DeltaTime();
		if (m_cannonTimer <= 0)
		{
			m_bShootCannon = true;
		}
	}
}

void LeukocyteShooting::Shoot()
{
	m_timer -= Time::DeltaTime();
	if (m_timer < 0)
	{
		for (auto b : m_vBullets)
		{
			if (b->GetActive() == false && static_cast<BulletControl*>(b->GetComponent("BulletControl"))->GetRun() == false)
			{
				static_cast<BulletControl*>(b->GetComponent("BulletControl"))->WakeUp();
				b->GetTransform()->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() - 30);
				m_timer = m_totalTime;
				m_pAudioEffect->Play();
				break;
			}
		}
	}
}

void LeukocyteShooting::ShootCannonball()
{
	for (auto cannonball : m_vCannonballs)
	{
		if (cannonball->GetActive() == false)
		{
			CannonballControl* pCannonballControl = static_cast<CannonballControl*> (cannonball->GetComponent("CannonballControl"));
			pCannonballControl->PlayAnimation(this->m_pSelfGameObject->GetTransform()->GetPosition());

		}
	}
}

void LeukocyteShooting::ShowNumCannon()
{
	std::string snumCannon = std::to_string(m_numCannon);
	char const*numCannon = snumCannon.c_str();
	pCannonBallNumTextMesh->LoadContent(numCannon, 30);
}

void LeukocyteShooting::OntriggerEnter(Collider & other)
{
	if (other.GetGameObject()->GetTag() == "CannonBall")
	{
		CannonBallGiftControl* pCannonBallGiftControl = static_cast<CannonBallGiftControl*>(other.GetGameObject()->GetTransform()->GetParent()->GetGameObject()->GetComponent("CannonBallGiftControl"));
		pCannonBallGiftControl->BHit();
		AddCannon(1);
	}
}





