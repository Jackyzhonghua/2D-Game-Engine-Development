#ifndef _VIRUS_BIG_BODY_CONTROL_H_
#define _VIRUS_BIG_BODY_CONTROL_H_
#include "GameBehavior.h"


class Transform;
class VirusBigBodyControl : public GameBehavior
{
public:
	VirusBigBodyControl(GameObject *pGameobject);
	~VirusBigBodyControl();

	virtual void Start()override;
	virtual void Update() override;

private:
	Transform *m_pTransform;
};
#endif
