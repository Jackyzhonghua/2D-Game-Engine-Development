#include "GameResultBackGround.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"


GameResultBackGround::GameResultBackGround(Scene* const selfScene) :GameObject("GameResultBackGround", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(350, 500);
	
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("GameResultBackGround"), this);
}


GameResultBackGround::~GameResultBackGround()
{
}
