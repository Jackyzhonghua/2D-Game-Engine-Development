#include "VirusSmallExplosion.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusSmallExplosionControl.h"


VirusSmallExplosion::VirusSmallExplosion(Scene* const selfScene) :GameObject("VirusSmallExplosion", selfScene)
{
	Transform *pTransform = new Transform(this);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusSmall_Explosion_01"), this);
	VirusSmallExplosionControl* pVirusSmallExplosionControl = new VirusSmallExplosionControl(this);
}


VirusSmallExplosion::~VirusSmallExplosion()
{
}
