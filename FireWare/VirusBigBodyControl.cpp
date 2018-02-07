#include "VirusBigBodyControl.h"
#include "GameObject.h"
#include "Transform.h"


VirusBigBodyControl::VirusBigBodyControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusBigBodyControl")
{
	m_pTransform = m_pSelfGameObject->GetTransform();
}


VirusBigBodyControl::~VirusBigBodyControl()
{
	m_pTransform = nullptr;
}

void VirusBigBodyControl::Start()
{
	m_pTransform->SetLocalPosition(0, 0);
}

void VirusBigBodyControl::Update()
{
}
