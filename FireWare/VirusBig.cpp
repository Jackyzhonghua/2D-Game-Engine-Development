#include "VirusBig.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "SphereCollider.h"
#include "VirusBigBody.h"
#include "VirusBigControl.h"


VirusBig::VirusBig(Scene* const selfScene) :VirusBas("VirusBig", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	SphereCollider *pSphereColliderr = new SphereCollider(this, 70);
	VirusBigControl *pVirusBigControl = new VirusBigControl(this);
}


VirusBig::~VirusBig()
{
}
