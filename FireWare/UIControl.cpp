#include "UIControl.h"
#include "CannonUI.h"
#include "GameManagerControl.h"
#include "CannonBallNumText.h"
#include "Transform.h"



UIControl::UIControl(GameObject *pGameobject) : GameBehavior(pGameobject, "UIControl")
{
	m_pCannonUI = new CannonUI(m_pSelfGameObject->GetSelfScene());
	//GameManagerControl::AddOpenGameobjects(m_pCannonUI);
	pCannonBallNumText = new CannonBallNumText(m_pSelfGameObject->GetSelfScene());
	
}


UIControl::~UIControl()
{
}

void UIControl::Start()
{
	m_pCannonUI->SetActive(false);
	pCannonBallNumText->SetActive(false);
}

void UIControl::Update()
{
	if (GameManagerControl::GetBStartGame())
	{
		m_pCannonUI->SetActive(true);
		pCannonBallNumText->SetActive(true);
	}
}
