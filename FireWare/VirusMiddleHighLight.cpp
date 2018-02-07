#include "VirusMiddleHighLight.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusMiddleHighLightControl.h"



VirusMiddleHighLight::VirusMiddleHighLight(Scene* const selfScene) :GameObject("VirusMiddleHighLight", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	m_tag = "Enemy";

	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusMiddle_highLight"), this);
	VirusMiddleHighLightControl *pVirusMiddleHighLightControl = new VirusMiddleHighLightControl(this);
}


VirusMiddleHighLight::~VirusMiddleHighLight()
{
}
