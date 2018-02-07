#include "GameManager.h"
#include "Scene.h"
#include "Transform.h"
#include "SourceManager.h"
#include "AudioSource.h"
#include "GameManagerControl.h"



GameManager::GameManager(Scene* const selfScene) :GameObject("GameManager", selfScene)
{
	Transform *pTransform = new Transform(this);
	AudioSource *pAudioSource = new AudioSource(SourceManager::GetMusic("BackGroundMusic"), this);
	GameManagerControl *pGameManagerControl = new GameManagerControl(this);
}


GameManager::~GameManager()
{
}
