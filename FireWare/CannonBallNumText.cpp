#include "CannonBallNumText.h"
#include "TextMesh.h"
#include "Transform.h"



CannonBallNumText::CannonBallNumText(Scene* const selfScene) :GameObject("CannonBallNumText", selfScene)
{
	Transform *pTransform = new Transform(this);
	GetTransform()->SetPosition(140, 80);

	TextMesh* pTextMesh = new TextMesh(this);
}


CannonBallNumText::~CannonBallNumText()
{
}
