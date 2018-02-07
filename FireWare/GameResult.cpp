#include "GameResult.h"
#include "Transform.h"
#include "TextMesh.h"
#include "GameResultControl.h"



GameResult::GameResult(Scene* const selfScene) :GameObject("GameResult", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(400, 500);

	TextMesh *pTextMesh = new TextMesh(this);
	GameResultControl *pGameResultControl = new GameResultControl(this);
}


GameResult::~GameResult()
{
}
