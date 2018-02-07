#ifndef _VIRUS_BIG_HIGH_LIGHT_CONTROL_H_
#define _VIRUS_BIG_HIGH_LIGHT_CONTROL_H_
#include "GameBehavior.h"

class Transform;
class VirusBigHighLightControl : public GameBehavior
{
public:
	VirusBigHighLightControl(GameObject *pGameobject);
	~VirusBigHighLightControl();

	virtual void Start()override;
	virtual void Update() override;

private:
	Transform *m_pTransform;
	double m_rotateSpeed;
	int m_rotateDir;

	void Rotate();
};
#endif
