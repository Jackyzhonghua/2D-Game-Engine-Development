#include "VirusSmall.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusSmallControl.h"
#include "SphereCollider.h"




VirusSmall::VirusSmall(Scene* const selfScene) :VirusBas("VirusSmall", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusSmall_body"), this);
	VirusSmallControl *pVirusSmallControl = new VirusSmallControl(this);
	SphereCollider *pSphereCollider = new SphereCollider(this, 20);
}

VirusSmall::~VirusSmall()
{

}



