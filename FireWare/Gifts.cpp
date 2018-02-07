#include "Gifts.h"
#include "Transform.h"
#include "GiftsControl.h"



Gifts::Gifts(Scene* const selfScene) :GameObject("Gifts", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);

	GiftsControl* pGiftsControl = new GiftsControl(this);
}


Gifts::~Gifts()
{
}
