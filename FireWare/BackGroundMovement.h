#ifndef _BACKGROUNDMOVEMENT_H_
#define _BACKGROUNDMOVEMENT_H_
#include "GameBehavior.h"

class Transform;
class GameObject;
class BackGroundMovement:public GameBehavior
{
public:
	BackGroundMovement(GameObject *pGameobject);
	~BackGroundMovement();


	virtual void Update() override;

private:
	double m_moveSpeed;
	double m_downBound;
	double m_upBound;

	Transform *m_pTransform;
};
#endif
