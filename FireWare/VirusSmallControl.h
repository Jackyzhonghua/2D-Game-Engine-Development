#ifndef _VIRUS_SMALL_CONTROL_H_
#define _VIRUS_SMALL_CONTROL_H_

#include "VirusBasControl.h"


class VirusSmallControl : public VirusBasControl
{
public:
	VirusSmallControl(GameObject *pGameobject);
	~VirusSmallControl();

	virtual void Explosion() override;

};
#endif
