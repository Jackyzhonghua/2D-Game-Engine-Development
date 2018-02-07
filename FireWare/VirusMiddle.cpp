#include "VirusMiddle.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusMiddleControl.h"
#include "SphereCollider.h"


VirusMiddle::VirusMiddle(Scene* const selfScene) :VirusBas("VirusMiddle", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusMiddle_body"), this);
	VirusMiddleControl *pVirusMiddleControl = new VirusMiddleControl(this);
	SphereCollider *pSphereCollider = new SphereCollider(this, 45);


}


VirusMiddle::~VirusMiddle()
{
}
