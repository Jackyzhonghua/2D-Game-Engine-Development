#ifndef _VIRUS_BIG_CONTROL_H
#define _VIRUS_BIG_CONTROL_H
#include "VirusBasControl.h"


class VirusBigControl : public VirusBasControl
{
public:
	VirusBigControl(GameObject *pGameobject);
	~VirusBigControl();

	virtual void Explosion() override;
};
#endif
