#include "VirusManagerControl.h"
#include "GameObject.h"
#include "VirusSmall.h"
#include "VirusMiddle.h"
#include "VirusMiddleHighLight.h"
#include "VirusSmallControl.h"
#include "VirusMiddleControl.h"
#include "VirusBig.h"
#include "VirusBigControl.h"
#include "VirusBigBody.h"
#include "VirusBigSideLight.h"
#include "VirusBigHighLight.h"
#include "Time.h"
#include "Transform.h"
#include "VirusSmallExplosion.h"
#include "VirusMiddleExplosion.h"
#include "VirusBigExplosion.h"


VirusManagerControl::VirusManagerControl(GameObject *pGameobject) : GameBehavior(pGameobject, "VirusManagerControl")
{
	m_timer = m_totalTime = 2;

	for (int i = 0; i < 40; ++i)
	{
		VirusBas *pVirusSmall = new VirusSmall(m_pSelfGameObject->GetSelfScene());
		m_virusSmall.push_back(pVirusSmall);
		if (i < 30)
		{
			VirusBas *pVirusMiddle = new VirusMiddle(m_pSelfGameObject->GetSelfScene());
			VirusMiddleHighLight *pVirusMiddleHighLight = new VirusMiddleHighLight(m_pSelfGameObject->GetSelfScene());
			pVirusMiddleHighLight->SetParent(pVirusMiddle);
			m_virusMiddle.push_back(pVirusMiddle);
		}
		if (i < 20)
		{
			VirusBig *pVirusBig = new VirusBig(m_pSelfGameObject->GetSelfScene());

			VirusBigHighLight *pVirusBigHighLight = new VirusBigHighLight(m_pSelfGameObject->GetSelfScene());
			pVirusBigHighLight->SetParent(pVirusBig);

			VirusBigSideLight *pVirusBigSideLight = new VirusBigSideLight(m_pSelfGameObject->GetSelfScene());
			pVirusBigSideLight->SetParent(pVirusBig);

			VirusBigBody *pVirusBigBody = new VirusBigBody(m_pSelfGameObject->GetSelfScene());
			pVirusBigBody->SetParent(pVirusBig);

			m_virusBig.push_back(pVirusBig);
		}
		if (i < 30)
		{
			VirusSmallExplosion* pVE = new VirusSmallExplosion(m_pSelfGameObject->GetSelfScene());
			m_pVirusSmallExplosions.push_back(pVE);
		}
		if (i < 20)
		{
			VirusMiddleExplosion* pVE = new VirusMiddleExplosion(m_pSelfGameObject->GetSelfScene());
			m_pVirusMiddleExplosions.push_back(pVE);
		}
		if (i < 10)
		{
			VirusBigExplosion* pVE = new VirusBigExplosion(m_pSelfGameObject->GetSelfScene());
			m_pVirusBigExplosions.push_back(pVE);
		}
	}
}


VirusManagerControl::~VirusManagerControl()
{
	for (auto vs : m_virusSmall)
	{
		vs = nullptr;
	}
	for (auto vm : m_virusMiddle)
	{
		vm = nullptr;
	}
	for (auto vb : m_virusBig)
	{
		vb = nullptr;
	}
	for (auto vse : m_pVirusSmallExplosions)
	{
		vse = nullptr;
	}
	for (auto vme : m_pVirusMiddleExplosions)
	{
		vme = nullptr;
	}
	for (auto vbe : m_pVirusBigExplosions)
	{
		vbe = nullptr;
	}
}


void VirusManagerControl::Update()
{
	SpawnControl();
}

void VirusManagerControl::GetExplosion()
{
	for (auto v : m_virusSmall)
	{
		if (v->GetActive())
		{
			static_cast<VirusBasControl*>(v->GetComponent("VirusSmallControl"))->GetExplosion();
		}
	}
	for (auto v : m_virusMiddle)
	{
		if (v->GetActive())
		{
			static_cast<VirusBasControl*>(v->GetComponent("VirusMiddleControl"))->GetExplosion();
		}
	}
	for (auto v : m_virusBig)
	{
		if (v->GetActive())
		{
			static_cast<VirusBasControl*>(v->GetComponent("VirusBigControl"))->GetExplosion();
		}
	}
}

VirusSmallExplosion * VirusManagerControl::GetVirusSmallExplosion()
{
	if (m_pVirusSmallExplosions.size() > 0)
	{
		for each (auto var in m_pVirusSmallExplosions)
		{
			if (!var->GetActive())
			{
				return var;
			}
		}
	}
	return nullptr;
}

VirusMiddleExplosion * VirusManagerControl::GetVirusMiddleExplosion()
{
	if (m_pVirusMiddleExplosions.size() > 0)
	{
		for each (auto var in m_pVirusMiddleExplosions)
		{
			if (!var->GetActive())
			{
				return var;
			}
		}
	}
	return nullptr;
}

VirusBigExplosion * VirusManagerControl::GetVirusBigExplosion()
{
	if (m_pVirusBigExplosions.size() > 0)
	{
		for each (auto var in m_pVirusBigExplosions)
		{
			if (!var->GetActive())
			{
				return var;
			}
		}
	}
	return nullptr;
}

void VirusManagerControl::SpawnControl()
{
	m_timer -= Time::DeltaTime();
	if (m_timer <= 0)
	{
		SpawnVirus();
		if(m_totalTime>0.2)
			m_totalTime -= 0.02;
		m_timer = m_totalTime;
	}
}

void VirusManagerControl::SpawnVirus()
{
	int randomIndex = rand() % 20;
	if (randomIndex < 10)
	{
		for (auto vs : m_virusSmall)
		{
			VirusSmallControl *pVirusSmallControl = static_cast<VirusSmallControl*>(vs->GetComponent("VirusSmallControl"));
			if (pVirusSmallControl->GetStatus())
			{
				pVirusSmallControl->Wakeup();
				break;
			}
		}
	}
	if (randomIndex < 14 && randomIndex >= 10)
	{
		for (auto vs : m_virusMiddle)
		{
			VirusMiddleControl *pVirusMiddleControl = static_cast<VirusMiddleControl*>(vs->GetComponent("VirusMiddleControl"));
			if (pVirusMiddleControl->GetStatus())
			{
				pVirusMiddleControl->Wakeup();
				break;
			}
		}
	}
	if(randomIndex == 15)
	{
		for (auto vs : m_virusBig)
		{
			VirusBigControl *pVirusMiddleControl = static_cast<VirusBigControl*>(vs->GetComponent("VirusBigControl"));
			if (pVirusMiddleControl->GetStatus())
			{
				pVirusMiddleControl->Wakeup();
				break;
			}
		}
	}
}
