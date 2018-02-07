#include "VirusManager.h"
#include "Transform.h"
#include "VirusManagerControl.h"



VirusManager::VirusManager(Scene* const selfScene) :GameObject("VirusManager", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	m_tag = "VirusManager";

	VirusManagerControl *pVirusManagerControl = new VirusManagerControl(this);
}


VirusManager::~VirusManager()
{
}

