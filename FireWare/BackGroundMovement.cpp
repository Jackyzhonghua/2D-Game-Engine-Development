#include "BackGroundMovement.h"
#include "Transform.h"
#include "GameObject.h"
#include "Time.h"


BackGroundMovement::BackGroundMovement(GameObject *pGameobject) : GameBehavior(pGameobject, "BackGroundMovement")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_moveSpeed = 60;
	m_downBound = 1750;
	m_upBound = -750;
}


BackGroundMovement::~BackGroundMovement()
{
}

void BackGroundMovement::Update()
{
	if (m_pTransform->GetPosition().Y() < m_downBound)
	{
		m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() + m_moveSpeed*Time::DeltaTime());
	}
	else
	{
		m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_upBound);
	}
}
