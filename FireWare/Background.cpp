#include "Background.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"



Background::Background(Scene* const selfScene) :GameObject("BackGround", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(350, 750);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("BackGround"), this);
}


Background::~Background()
{
}
