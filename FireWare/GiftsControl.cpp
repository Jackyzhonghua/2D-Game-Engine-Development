#include "GiftsControl.h"
#include "CannonBallGift.h"
#include "CannonBallGiftControl.h"



GiftsControl::GiftsControl(GameObject *pGameobject) : GameBehavior(pGameobject, "GiftsControl")
{
	for (int i = 0; i < 20; ++i)
	{
		CannonBallGift* pCannonBallGift = new CannonBallGift(m_pSelfGameObject->GetSelfScene());
		m_CannonBallGiftControls.push_back(static_cast<CannonBallGiftControl*>(pCannonBallGift->GetComponent("CannonBallGiftControl")));
	}
}


GiftsControl::~GiftsControl()
{

}

CannonBallGiftControl * GiftsControl::GetACannonBallGiftControl()
{
	for (auto c : m_CannonBallGiftControls)
	{
		if (!c->IsMoving())
		{
			return c;
		}
	}
	return nullptr;
}

void GiftsControl::Awake()
{
	
}
