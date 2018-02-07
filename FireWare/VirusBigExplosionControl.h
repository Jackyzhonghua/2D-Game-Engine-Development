#ifndef _VIRUS_BIG_EXPLOSION_CONTROL_H
#define _VIRUS_BIG_EXPLOSION_CONTROL_H
#include "GameBehavior.h"
#include <vector>

class Transform;
class Sprite;
class SpriteRederer;
class Vector2;
class VirusBigExplosionControl : public GameBehavior
{
public:
	VirusBigExplosionControl(GameObject *pGameobject);
	~VirusBigExplosionControl();

	void PlayAnimation(Vector2 positopn);

private:
	Transform *m_pTransform;
	SpriteRederer* m_pSpriteRender;
	std::vector<Sprite*> m_sprites;
	double m_timer;
	double m_totalTime;
	int m_index;

	virtual void Start() override;
	virtual void Update() override;


};
#endif
