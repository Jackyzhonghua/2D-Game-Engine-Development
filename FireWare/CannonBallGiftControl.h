#ifndef _CONNON_BALL_GIFT_CONTROL_H
#define _CONNON_BALL_GIFT_CONTROL_H
#include "GameBehavior.h"


class Transform;
class Vector2;
class AudioEffect;
class CannonBallGiftControl :public GameBehavior
{
public:
	CannonBallGiftControl(GameObject *pGameobject);
	~CannonBallGiftControl();


	void Hid();
	void BHit();
	void Show(Vector2 newpos);
	bool IsMoving() { return m_bMove; }

private:
	Transform* m_pTransform;
	AudioEffect *m_pAudioEffect;
	double m_rotateSpeed;
	Transform* pInsideTransform;
	bool m_bMove;
	double m_moveSpeed;

	void rotate();
	void move();
	virtual void Update() override;

};
#endif
