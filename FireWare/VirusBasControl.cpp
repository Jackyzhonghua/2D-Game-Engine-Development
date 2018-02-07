#include "VirusBasControl.h"
#include "Transform.h"
#include "GameObject.h"
#include "Time.h"
#include "Radom.h"
#include "Collider.h"
#include "LeukocyteMoveControl.h"
#include "Scene.h"
#include "VirusManagerControl.h"
#include "GiftsControl.h"
#include "CannonBallGiftControl.h"


VirusBasControl::VirusBasControl(GameObject * pGameobject, std::string name) : GameBehavior(pGameobject, name)
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	int dir = Radom::Range(0, 2);
	if (dir == 0)
		m_rotateLeft = -1;
	else
		m_rotateLeft = 1;

	m_pVirusManagerControl = static_cast<VirusManagerControl*>( m_pSelfGameObject->GetSelfScene()->findGameObject("VirusManager")->GetComponent("VirusManagerControl"));
	Dead();
	m_pGiftsControl = nullptr;
}

VirusBasControl::~VirusBasControl()
{
	m_pTransform = nullptr;
}

void VirusBasControl::Start()
{
	m_pGiftsControl = static_cast<GiftsControl*>(m_pSelfGameObject->GetSelfScene()->findGameObject("Gifts")->GetComponent("GiftsControl"));
}

void VirusBasControl::Update()
{
	Move();
	Rotate();
}

void VirusBasControl::Move()
{
	if (m_bDead == true) return;
	if (m_pTransform->GetPosition().Y() > 1000)
	{
		Dead();
	}

	m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() + m_moveSpeed * Time::DeltaTime());
}

void VirusBasControl::Rotate()
{
	m_pTransform->SetRotation(m_pTransform->GetRotation() + m_rotateLeft * m_rotateSpeed*Time::DeltaTime());
}

void VirusBasControl::OntriggerEnter(Collider & other)
{
	if (other.GetGameObject()->GetTag() == "Player")
	{
		Dead();
		static_cast<LeukocyteMoveControl*>(other.GetGameObject()->GetComponent("LeukocyteMoveControl"))->Dead();
	}
}

void VirusBasControl::GetDamage(int demage)
{
	if (m_bDead) return;
	m_curBlood -= demage;
	if (m_curBlood <= 0)
	{
		int randomIndex = rand() % 30;
		if (randomIndex < 2)
		{
			m_pGiftsControl->GetACannonBallGiftControl()->Show(m_pTransform->GetPosition());
		}
		Explosion();
		Dead();
	}
}

void VirusBasControl::GetExplosion()
{
	GetDamage(m_curBlood);
}

void VirusBasControl::Dead()
{
	GameObject *pPlayer = m_pSelfGameObject->GetSelfScene()->findGameObject("Leukocyte");
	LeukocyteMoveControl *pLeukocyteMoveControl = static_cast<LeukocyteMoveControl*>(pPlayer->GetComponent("LeukocyteMoveControl"));
	pLeukocyteMoveControl->AddScore(m_point);
	m_pSelfGameObject->SetActive(false);
	m_bDead = true;
}

void VirusBasControl::Wakeup()
{
	m_pSelfGameObject->SetActive(true);
	GetRandomPlace();
	m_curBlood = m_blood;
	m_bDead = false;
}

void VirusBasControl::GetRandomPlace()
{
	int placePoint = rand() % 700;
	m_pTransform->SetPosition(placePoint, -80);
}
