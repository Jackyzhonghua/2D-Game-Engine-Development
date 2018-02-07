#ifndef _VIRUS_MIDDLE_HIGH_LIGHT_CONTROL_H_
#define _VIRUS_MIDDLE_HIGH_LIGHT_CONTROL_H_


#include "GameBehavior.h"

class SpriteRederer;
class Transform;
class VirusMiddleHighLightControl : public GameBehavior
{
public:
	VirusMiddleHighLightControl(GameObject *pGameobject);
	~VirusMiddleHighLightControl();

	virtual void Start()override;
	virtual void Update() override;
private:
	SpriteRederer * m_pSpriteRenderer;
	Transform *m_pTransform;
	bool m_bGolower;
	double m_changeSpeed;
	void AlphaControl();
};
#endif
