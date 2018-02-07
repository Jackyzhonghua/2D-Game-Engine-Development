#ifndef _VIRUS_BIG_SIDE_LIGHT_CONTROL_H_
#define _VIRUS_BIG_SIDE_LIGHT_CONTROL_H_
#include "GameBehavior.h"

class Transform;
class SpriteRederer;
class VirusBigSideLightControl : public GameBehavior
{
public:
	VirusBigSideLightControl(GameObject *pGameobject);
	~VirusBigSideLightControl();

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
