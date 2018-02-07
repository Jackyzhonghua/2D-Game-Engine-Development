#include "VirusBigHighLight.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusBigHighLightControl.h"


VirusBigHighLight::VirusBigHighLight(Scene* const selfScene) :GameObject("VirusBigHighLight", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	m_tag = "Enemy";
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusBig_highLight"), this);
	VirusBigHighLightControl *pVirusBigHighLightControl = new VirusBigHighLightControl(this);
}


VirusBigHighLight::~VirusBigHighLight()
{
}
