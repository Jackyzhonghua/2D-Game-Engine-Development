#include "Leukocyte.h"
#include "Transform.h"
#include "Sprite.h"
#include "SpriteRederer.h"
#include "LeukocyteMoveControl.h"
#include "SourceManager.h"
#include "LeukocyteShooting.h"
#include "VirusManager.h"
#include "SphereCollider.h"
#include "AudioEffect.h"



Leukocyte::Leukocyte(Scene* const selfScene):GameObject("Leukocyte",selfScene)
{
	Transform *pTransform=new Transform(this);
	pTransform->SetPosition(350, 900);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("Leukocyte"), this);
	AudioEffect *pAudioEffect = new AudioEffect(SourceManager::GetSoundEffect("Shoot"), this);
	LeukocyteMoveControl *pLeukocyteMoveControl = new LeukocyteMoveControl(this);
	LeukocyteShooting *pLeukocyteShooting = new LeukocyteShooting(this);
	m_tag = "Player";

	SphereCollider *pSphereCollider = new SphereCollider(this, 45);
}


Leukocyte::~Leukocyte()
{
}
