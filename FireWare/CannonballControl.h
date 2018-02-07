#ifndef _CANNONBALL_CONTROL_H
#define _CANNONBALL_CONTROL_H
#include "GameBehavior.h"
#include <vector>


class Sprite;
class Vector2;
class Transform;
class SpriteRederer;
class VirusManagerControl;
class AudioEffect;
class CannonballControl : public GameBehavior
{
public:
	CannonballControl(GameObject *pGameobject);
	~CannonballControl();

	void PlayAnimation(Vector2 positopn);

private:
	Transform *m_pTransform;
	SpriteRederer* m_pSpriteRender;
	AudioEffect *m_pAudioEffect;
	std::vector<Sprite*> m_sprites;
	bool m_bExplode;
	double m_timer;
	double m_totalTime;
	double m_changeSpeed;
	double m_moveSpeed;
	int m_index;

	VirusManagerControl* m_pVirusManagerControl;



	virtual void Start() override;
	virtual void Update() override;

};
#endif
