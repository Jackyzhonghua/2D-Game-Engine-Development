#include "CannonBallGiftControl.h"
#include "GameObject.h"
#include "CannonBallGiftInside.h"
#include "Transform.h"
#include "Time.h"
#include "AudioEffect.h"


CannonBallGiftControl::CannonBallGiftControl(GameObject *pGameobject) : GameBehavior(pGameobject, "CannonBallGiftControl")
{
	m_pTransform = m_pSelfGameObject->GetTransform();
	m_pTransform->SetPosition(300, 100);
	m_pAudioEffect = static_cast<AudioEffect*>(m_pSelfGameObject->GetComponent(k_audioEffect));


	GameObject*  pCannonBallGiftInside = new CannonBallGiftInside(m_pSelfGameObject->GetSelfScene());
	pCannonBallGiftInside->SetParent(m_pSelfGameObject);
	pInsideTransform = pCannonBallGiftInside->GetTransform();
	pInsideTransform->SetLocalPosition(100, 0);

	m_rotateSpeed = 100;
	m_moveSpeed = 50;
	Hid();
}


CannonBallGiftControl::~CannonBallGiftControl()
{
	m_pTransform = nullptr;
}

void CannonBallGiftControl::Hid()
{
	m_pTransform->SetPosition(-300, -300);
	pInsideTransform->SetLocalPosition(100, 0);
	m_bMove = false;
}

void CannonBallGiftControl::BHit()
{
	m_pAudioEffect->Play();
	Hid();
}

void CannonBallGiftControl::Show(Vector2 newpos)
{
	m_pTransform->SetPosition(newpos);
	m_bMove = true;
}

void CannonBallGiftControl::rotate()
{
	pInsideTransform->Rotate(-m_rotateSpeed*Time::DeltaTime());
	m_pTransform->Rotate(m_rotateSpeed*Time::DeltaTime());
}

void CannonBallGiftControl::move()
{
	m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() + Time::DeltaTime()*m_moveSpeed);
}



void CannonBallGiftControl::Update()
{
	if (m_bMove)
	{
		move();
		rotate();
	}
}


