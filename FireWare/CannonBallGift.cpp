#include "CannonBallGift.h"
#include "GameObject.h"
#include "Transform.h"
#include "CannonBallGiftControl.h"
#include "AudioEffect.h"
#include "SourceManager.h"


CannonBallGift::CannonBallGift(Scene* const selfScene) :GameObject("CannonBallGift", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	AudioEffect *pAudioEffect = new AudioEffect(SourceManager::GetSoundEffect("Gift"), this);

	CannonBallGiftControl* pCannonBallGiftControl = new CannonBallGiftControl(this);
}


CannonBallGift::~CannonBallGift()
{

}
