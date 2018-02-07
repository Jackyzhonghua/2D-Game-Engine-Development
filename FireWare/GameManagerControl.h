#ifndef _GAME_MANAGER_CONTROL_H_
#define _GAME_MANAGER_CONTROL_H_
#include "GameBehavior.h"
#include <iostream>
#include <vector>

class AudioSource;
class GameObject;
class GameManagerControl :public GameBehavior
{
public:
	GameManagerControl(GameObject *pGameobject);
	~GameManagerControl();



	static void SetBStartGame(bool bStartGame);
	static void SetBFinishGame(bool bFinishGame);
	static bool GetBStartGame(){ return m_bStartGame;}
	static bool GetbFinishGame() { return m_bFinishGame; }

	//issue
	static void AddOpenGameobjects(GameObject* gameObject);

private:
	AudioSource *m_pAudioSource;

	static bool m_bStartGame;
	static bool m_bFinishGame;
};
#endif
