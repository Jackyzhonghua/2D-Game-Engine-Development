#ifndef _GIFTS_CONTROL_H_
#define _GIFTS_CONTROL_H_
#include "GameBehavior.h"
#include <vector>


class CannonBallGiftControl;
class GiftsControl :public GameBehavior
{
public:
	GiftsControl(GameObject *pGameobject);
	~GiftsControl();

	CannonBallGiftControl* GetACannonBallGiftControl();

private:
	std::vector<CannonBallGiftControl*> m_CannonBallGiftControls;

	virtual void Awake() override;
};
#endif
