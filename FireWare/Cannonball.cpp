#include "Cannonball.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "CannonballControl.h"
#include "AudioEffect.h"


Cannonball::Cannonball(Scene* const selfScene) :GameObject("Cannonball", selfScene)
{
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("cannonball_01"), this);
	AudioEffect *pAudioEffect = new AudioEffect(SourceManager::GetSoundEffect("Explosion"), this);
	CannonballControl *pCannonballControl = new CannonballControl(this);
}


Cannonball::~Cannonball()
{

}
