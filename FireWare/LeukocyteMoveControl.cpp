#include "LeukocyteMoveControl.h"
#include "Collider.h"
#include "GameObject.h"
#include "Input.h"
#include "Time.h"
#include "Transform.h"
#include "Scene.h"
#include "GameResultControl.h"
#include <string>
#include "GameManagerControl.h"


LeukocyteMoveControl::LeukocyteMoveControl(GameObject *pGameobject) : GameBehavior(pGameobject, "LeukocyteMoveControl")
{
	m_pTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_moveSpeed = 600;
	m_rotateSpeed = 60;
}


LeukocyteMoveControl::~LeukocyteMoveControl()
{
	m_pTransform = nullptr;
	pGameResultBackGround = nullptr;
}

void LeukocyteMoveControl::Awake()
{
	pGameResultBackGround = m_pSelfGameObject->GetSelfScene()->findGameObject("GameResultBackGround");
	pGameResultBackGround->SetActive(false);
}

void LeukocyteMoveControl::Update()
{
	MoveControl();
	RotateControl();
}

void LeukocyteMoveControl::Dead()
{
	m_pSelfGameObject->SetActive(false);
	//set GameResultBackGround
	pGameResultBackGround->SetActive(true);

	GameObject *pGameResult = m_pSelfGameObject->GetSelfScene()->findGameObject("GameResult");
	GameResultControl *pGameResultControl = static_cast<GameResultControl*>(pGameResult->GetComponent("GameResultControl"));
	std::string sScore = std::to_string(m_score);
	char const*cScore = sScore.c_str();
	pGameResultControl->Show(cScore, 30);
	GameManagerControl::SetBFinishGame(true);
}

void LeukocyteMoveControl::AddScore(int score)
{
	m_score += score;
}


void LeukocyteMoveControl::MoveControl()
{
	if (Input::GetButtonDown(D))
	{
		if (m_pTransform->GetPosition().X() < 700)
			m_pTransform->SetPosition(m_pTransform->GetPosition().X() + m_moveSpeed*Time::DeltaTime(), m_pTransform->GetPosition().Y());
	}
	if (Input::GetButtonDown(A))
	{
		if (m_pTransform->GetPosition().X() > 0)
			m_pTransform->SetPosition(m_pTransform->GetPosition().X() - m_moveSpeed * Time::DeltaTime(), m_pTransform->GetPosition().Y());
	}
	if (Input::GetButtonDown(W))
	{
		if (m_pTransform->GetPosition().Y() > 0)
			m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() - m_moveSpeed * Time::DeltaTime());
	}
	if (Input::GetButtonDown(S))
	{
		if (m_pTransform->GetPosition().Y() < 1000)
			m_pTransform->SetPosition(m_pTransform->GetPosition().X(), m_pTransform->GetPosition().Y() + m_moveSpeed * Time::DeltaTime());
	}
}

void LeukocyteMoveControl::RotateControl()
{
	m_pTransform->SetRotation(m_pTransform->GetRotation() + m_moveSpeed*Time::DeltaTime());
}
