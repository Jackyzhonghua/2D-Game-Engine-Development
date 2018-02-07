#include "Bullet.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "BulletControl.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "AudioEffect.h"



Bullet::Bullet(Scene* const selfScene) :GameObject("Bullet", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("Bullet"), this);
	AudioEffect *pAudioEffect = new AudioEffect(SourceManager::GetSoundEffect("Hit"), this);
	BoxCollider *pBoxCollider = new BoxCollider(this, 3, 8, 3, 8);

	BulletControl *pBulletControl = new BulletControl(this);
	
}


Bullet::~Bullet()
{
}
