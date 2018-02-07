#include "StartMenuBackgroundControl.h"
#include "Input.h"
#include "GameManagerControl.h"
#include "GameObject.h"



StartMenuBackgroundControl::StartMenuBackgroundControl(GameObject *pGameobject) : GameBehavior(pGameobject, "StartMenuBackgroundControl")
{

}


StartMenuBackgroundControl::~StartMenuBackgroundControl()
{
}

void StartMenuBackgroundControl::Update()
{
	if (GameManagerControl::GetBStartGame())
	{
		m_pSelfGameObject->SetActive(false);
	}
}

