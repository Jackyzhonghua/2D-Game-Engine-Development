#include "VirusMiddleControl.h"
#include  "Transform.h"
#include "Time.h"
#include "VirusManagerControl.h"
#include "VirusMiddleExplosion.h"
#include "VirusMiddlelExplosionControl.h"


VirusMiddleControl::VirusMiddleControl(GameObject *pGameobject) : VirusBasControl(pGameobject, "VirusMiddleControl")
{
	m_moveSpeed = 150;
	m_rotateSpeed = 40;
	m_blood = 3;
	m_curBlood = m_blood;
	m_point = 300;
	m_bDead = true;
}


VirusMiddleControl::~VirusMiddleControl()
{
}

void VirusMiddleControl::Explosion()
{
	VirusMiddleExplosion* pVe = m_pVirusManagerControl->GetVirusMiddleExplosion();
	if (!pVe)
	{
		return;
	}
	VirusMiddlelExplosionControl* pVeCon = static_cast<VirusMiddlelExplosionControl*>(pVe->GetComponent("VirusSmallExplosionControl"));
	pVeCon->PlayAnimation(m_pSelfGameObject->GetTransform()->GetPosition());
}
