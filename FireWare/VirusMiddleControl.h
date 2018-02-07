#ifndef _VIRUS_MIDDLE_CONTROL_H_
#define _VIRUS_MIDDLE_CONTROL_H_
#include "VirusBasControl.h"

class VirusMiddleControl : public VirusBasControl
{
public:
	VirusMiddleControl(GameObject *pGameobject);
	~VirusMiddleControl();

	virtual void Explosion() override;
};
#endif
