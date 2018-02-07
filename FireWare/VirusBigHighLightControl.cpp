#include "VirusBigHighLightControl.h"
#include "GameObject.h"
#include "Transform.h"
#include "Radom.h"


VirusBigHighLightControl::VirusBigHighLightControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusBigHighLightControl")
{
	m_pTransform = m_pSelfGameObject->GetTransform();
	m_rotateSpeed = 3;
	int dir = Radom::Range(0, 2);
	if (dir == 0)
		m_rotateDir = -1;
	else
		m_rotateDir = 1;
}


VirusBigHighLightControl::~VirusBigHighLightControl()
{
	m_pTransform = nullptr;
}

void VirusBigHighLightControl::Start()
{
	m_pTransform->SetLocalPosition(0, 0);
}

void VirusBigHighLightControl::Update()
{
	Rotate();
}

void VirusBigHighLightControl::Rotate()
{
	m_pTransform->Rotate(m_rotateSpeed * m_rotateDir);
}
