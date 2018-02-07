#ifndef _LEUKOCYTEMOVECONTROL_H_
#define _LEUKOCYTEMOVECONTROL_H_
#include "GameBehavior.h"
#include <iostream>
#include <string.h>

class Collider;
class GameObject;
class Transform;
class LeukocyteMoveControl : public GameBehavior
{
public:
	LeukocyteMoveControl(GameObject *pGameobject);
	~LeukocyteMoveControl();
	virtual void Awake() override;
	virtual void Start() override{}
	virtual void Update() override;

	virtual void Dead();

	void AddScore(int score);
private:
	Transform *m_pTransform;
	double m_moveSpeed;
	double m_rotateSpeed;
	int m_score;

	GameObject *pGameResultBackGround;

	void MoveControl();
	void RotateControl();
};
#endif  
