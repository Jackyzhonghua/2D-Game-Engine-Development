#ifndef _START_MENU_BACKGROUND_CONTROL_H_
#define _START_MENU_BACKGROUND_CONTROL_H_

#include "GameBehavior.h"

class StartMenuBackgroundControl :public GameBehavior
{
public:
	StartMenuBackgroundControl(GameObject *pGameobject);
	~StartMenuBackgroundControl();


	virtual void Awake() override{}
	virtual void Start() override {}
	virtual void Update() override;


};
#endif

