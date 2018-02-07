#ifndef _LEULOCYTELIGHTCONTROL_H_
#define _LEULOCYTELIGHTCONTROL_H_
#include "GameBehavior.h"

class SpriteRederer;
class Transform;
class LeukocyteLightControl : public GameBehavior
{
public:
	LeukocyteLightControl(GameObject *pGameobject);
	~LeukocyteLightControl();

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

