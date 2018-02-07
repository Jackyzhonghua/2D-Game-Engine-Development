#include "VirusBigControl.h"
#include  "Transform.h"
#include "Time.h"
#include "VirusManagerControl.h"
#include "VirusBigExplosion.h"
#include "VirusBigExplosionControl.h"



VirusBigControl::VirusBigControl(GameObject *pGameobject) : VirusBasControl(pGameobject, "VirusBigControl")
{
	m_moveSpeed = 120;
	m_rotateSpeed = 30;
	m_blood = 10;
	m_curBlood = m_blood;
	m_point = 1000;
	m_bDead = true;
}


VirusBigControl::~VirusBigControl()
{
}

void VirusBigControl::Explosion()
{
	VirusBigExplosion* pVe = m_pVirusManagerControl->GetVirusBigExplosion();
	if (!pVe)
	{
		return;
	}
	VirusBigExplosionControl* pVeCon = static_cast<VirusBigExplosionControl*>(pVe->GetComponent("VirusBigExplosionControl"));
	pVeCon->PlayAnimation(m_pSelfGameObject->GetTransform()->GetPosition());
}