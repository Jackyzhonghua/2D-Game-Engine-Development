#include "CannonUI.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"



CannonUI::CannonUI(Scene* const selfScene) :GameObject("CannonUI", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(90, 60);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("CannonUI"), this);
}


CannonUI::~CannonUI()
{
}
