#include "GameResultControl.h"
#include "GameObject.h"
#include "TextMesh.h"


GameResultControl::GameResultControl(GameObject *pGameobject) : GameBehavior(pGameobject, "GameResultControl")
{
}


GameResultControl::~GameResultControl()
{
}

void GameResultControl::Awake()
{
	hide();
}

void GameResultControl::Show(const char * pAddress, const char * content, int size)
{
	m_pSelfGameObject->SetActive(true);
	TextMesh *pTextMesh = static_cast<TextMesh*>(m_pSelfGameObject->GetComponent(k_textMesh));
	pTextMesh->LoadContent(pAddress, content, size);
}

void GameResultControl::Show(const char * content, int size)
{
	m_pSelfGameObject->SetActive(true);
	TextMesh *pTextMesh = static_cast<TextMesh*>(m_pSelfGameObject->GetComponent(k_textMesh));
	pTextMesh->LoadContent(content, size);
}

void GameResultControl::hide()
{
	m_pSelfGameObject->SetActive(false);
}
