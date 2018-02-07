#include "VirusMiddleExplosion.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "VirusMiddlelExplosionControl.h"


VirusMiddleExplosion::VirusMiddleExplosion(Scene* const selfScene) :GameObject("VirusMiddleExplosion", selfScene)
{
	Transform *pTransform = new Transform(this);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("VirusMiddle_Explosion_01"), this);
	VirusMiddlelExplosionControl* pVirusMiddlelExplosionControl = new VirusMiddlelExplosionControl(this);
}


VirusMiddleExplosion::~VirusMiddleExplosion()
{
}
