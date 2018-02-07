#ifndef _BULLET_CONTROL_H_
#define _BULLET_CONTROL_H_
#include "GameBehavior.h"

class GameBehavior;
class Transform;
class GameObject;
class AudioEffect;
class BulletControl :public GameBehavior
{
public:
	BulletControl(GameObject *pGameobject);
	~BulletControl();

	void SetRun(bool bRun);
	bool GetRun()const { return m_bRun; }
	void Dead();
	void WakeUp();

	virtual void OntriggerEnter(Collider &other) override;
private: 
	Transform *m_pTransform;
	AudioEffect *m_pAudioEffect;
	double m_moveSpeed;
	bool m_bRun;

	virtual void Start() override;
	virtual void Update() override;

	void Move();
};
#endif
