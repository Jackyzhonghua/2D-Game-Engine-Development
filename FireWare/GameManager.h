#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_
#include "GameObject.h"

class GameManager :public GameObject
{
public:
	GameManager(Scene* const selfScene);
	~GameManager();

};
#endif;
