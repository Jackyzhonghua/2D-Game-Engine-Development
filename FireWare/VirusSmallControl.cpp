#include "VirusSmallControl.h"
#include  "Transform.h"
#include "Time.h"
#include "VirusManagerControl.h"
#include "VirusSmallExplosion.h"
#include "VirusSmallExplosionControl.h"



VirusSmallControl::VirusSmallControl(GameObject *pGameobject) : VirusBasControl(pGameobject, "VirusSmallControl")
{
	m_moveSpeed = 180;
	m_rotateSpeed = 60;
	m_blood = 1;
	m_point = 100;
	m_curBlood = m_blood;
	m_bDead = true;

}


VirusSmallControl::~VirusSmallControl()
{
}


void VirusSmallControl::Explosion()
{
	VirusSmallExplosion* pVe = m_pVirusManagerControl->GetVirusSmallExplosion();
	if (!pVe)
	{
		return;
	}
	VirusSmallExplosionControl* pVeCon = static_cast<VirusSmallExplosionControl*>(pVe->GetComponent("VirusSmallExplosionControl"));
	pVeCon->PlayAnimation(m_pSelfGameObject->GetTransform()->GetPosition());
}


