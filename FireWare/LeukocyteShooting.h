#ifndef _LEUKOCYTE_SHOOTING_H_
#define _LEUKOCYTE_SHOOTING_H_
#include "GameBehavior.h"
#include <iostream>
#include <vector>


class Bullet;
class Transform;
class AudioEffect;
class Cannonball;
class TextMesh;
class LeukocyteShooting : public GameBehavior
{
public:
	LeukocyteShooting(GameObject *pGameobject);
	~LeukocyteShooting();

	virtual void Awake() override;

	void AddCannon(int num);

private:
	Transform *m_pTransform;
	std::vector<Bullet*> m_vBullets;
	std::vector<Cannonball*> m_vCannonballs;

	double m_timer;
	double m_totalTime;


	double m_cannonTimer;
	double m_totalCannonTime;
	bool m_bShootCannon;
	int m_numCannon;
	TextMesh* pCannonBallNumTextMesh;

	AudioEffect *m_pAudioEffect;




	virtual void Update() override;
	void Shoot();
	void ShootCannonball();
	void ShowNumCannon();

	virtual void OntriggerEnter(Collider &other) override;
};
#endif
