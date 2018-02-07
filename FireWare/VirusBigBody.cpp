#include "VirusBigBody.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusBigBodyControl.h"


VirusBigBody::VirusBigBody(Scene* const selfScene) :GameObject("VirusBigBody", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	m_tag = "Enemy";
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusBig_body"), this);
	VirusBigBodyControl *pVirusBigBodyControl = new VirusBigBodyControl(this);
}


VirusBigBody::~VirusBigBody()
{
}
