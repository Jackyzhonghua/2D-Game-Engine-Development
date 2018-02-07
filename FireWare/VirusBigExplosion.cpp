#include "VirusBigExplosion.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusBigExplosionControl.h"


VirusBigExplosion::VirusBigExplosion(Scene* const selfScene) :GameObject("VirusBigExplosion", selfScene)
{
	Transform *pTransform = new Transform(this);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusBig_Explosion_01"), this);
	VirusBigExplosionControl* pVirusBigExplosionControl = new VirusBigExplosionControl(this);
}


VirusBigExplosion::~VirusBigExplosion()
{
}
