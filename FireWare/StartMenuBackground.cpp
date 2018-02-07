#include "StartMenuBackground.h"
#include "Transform.h"
#include "SpriteRederer.h"
#include "SourceManager.h"
#include "StartMenuBackgroundControl.h"


StartMenuBackground::StartMenuBackground(Scene* const selfScene) :GameObject("StartMenuBackground", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(350, 500);
	SpriteRederer *pSpriteRederer = new SpriteRederer(SourceManager::GetSprite("StartMenuBackground"), this);
	StartMenuBackgroundControl *pStartMenuBackgroundControl = new StartMenuBackgroundControl(this);
}


StartMenuBackground::~StartMenuBackground()
{
}
