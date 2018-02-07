#include "LeukocyteLight.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "LeukocyteLightControl.h"




LeukocyteLight::LeukocyteLight(Scene* const selfScene) :GameObject("LeukocyteLight", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	m_tag = "Player";

	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("LeukocyteLight"), this);
	LeukocyteLightControl *pLeukocyteLightControl = new LeukocyteLightControl(this);
}


LeukocyteLight::~LeukocyteLight()
{
}


