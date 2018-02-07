#ifndef _GAME_RESULT_CONTROL_H
#define _GAME_RESULT_CONTROL_H
#include "GameBehavior.h"

class GameObject;
class GameResultControl :public GameBehavior
{
public:
	GameResultControl(GameObject *pGameobject);
	~GameResultControl();

	virtual void Awake() override;
	virtual void Start() override {}
	virtual void Update() override{}

	void Show(const char * pAddress, const char *content, int size);
	void Show(const char *content, int size);
	void hide();

};
#endif
