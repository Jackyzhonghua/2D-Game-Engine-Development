#ifndef _VIRUS_BAS_CONTROL_H_
#define _VIRUS_BAS_CONTROL_H_
#include "GameBehavior.h"
#include <iostream>
#include <string.h>

class Transform;
class VirusManagerControl;
class GiftsControl;
class VirusBasControl :public GameBehavior
{
public:
	VirusBasControl(GameObject *pGameobject, std::string name);
	~VirusBasControl();
	
	virtual void GetDamage(int demage = 1);
	virtual void GetExplosion();
	virtual void Explosion() = 0;
	virtual void Dead() ;
	virtual void Wakeup() ;

	bool GetStatus() const { return m_bDead; }
protected:
	double m_moveSpeed;
	double m_rotateSpeed;
	int m_rotateLeft;//rotate direction

	int m_blood;
	int m_curBlood;
	int m_point;
	bool m_bDead;
	Transform *m_pTransform;

	VirusManagerControl* m_pVirusManagerControl;

	virtual void Start() override;
	virtual void Update() override;
	virtual void Move();
	virtual void Rotate();
	virtual void OntriggerEnter(Collider &other) override;
	

	void GetRandomPlace();

private:
	GiftsControl* m_pGiftsControl;

	
};
#endif
