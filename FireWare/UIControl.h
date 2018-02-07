#ifndef _UI_CONTROL_H_
#define _UI_CONTROL_H_
#include "GameBehavior.h"

class GameObject;
class UIControl :public GameBehavior
{
public:
	UIControl(GameObject *pGameobject);
	~UIControl();


	virtual void Awake() override {}
	virtual void Start() override;
	virtual void Update() override;

	GameObject* m_pCannonUI;
	GameObject* pCannonBallNumText;
};
#endif
