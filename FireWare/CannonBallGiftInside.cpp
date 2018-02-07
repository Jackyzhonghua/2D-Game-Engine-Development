#include "CannonBallGiftInside.h"
#include "SourceManager.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "BoxCollider.h"



CannonBallGiftInside::CannonBallGiftInside(Scene* const selfScene) :GameObject("CannonBallGiftInside", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);
	SpriteRederer* pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("CannonBallGift"), this);
	BoxCollider* pBoxCollider = new BoxCollider(this,44,22,44,22);
	m_tag = "CannonBall";
}


CannonBallGiftInside::~CannonBallGiftInside()
{
}
