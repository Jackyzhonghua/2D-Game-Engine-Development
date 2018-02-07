#include "VirusBigSideLight.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusBigSideLightControl.h"


VirusBigSideLight::VirusBigSideLight(Scene* const selfScene) : GameObject("VirusBigSideLight", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	m_tag = "Enemy";
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusBig_sideLight"), this);
	VirusBigSideLightControl *pVirusBigBodySideLightControl = new VirusBigSideLightControl(this);
}


VirusBigSideLight::~VirusBigSideLight()
{
}
