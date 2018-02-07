#include "GameManagerControl.h"
#include "GameObject.h"
#include "Scene.h"
#include "AudioSource.h"

bool GameManagerControl::m_bStartGame = false;
bool GameManagerControl::m_bFinishGame = false;

GameManagerControl::GameManagerControl(GameObject *pGameobject) : GameBehavior(pGameobject, "GameManagerControl")
{
	m_pAudioSource = static_cast<AudioSource*>(m_pSelfGameObject->GetComponent(k_audioSource));
}


GameManagerControl::~GameManagerControl()
{
}

void GameManagerControl::SetBStartGame(bool bStartGame)
{
	m_bStartGame = bStartGame;
}

void GameManagerControl::SetBFinishGame(bool bFinishGame)
{
	m_bFinishGame = bFinishGame;
}

void GameManagerControl::AddOpenGameobjects(GameObject * gameObject)
{
}
