#ifndef _SPHERECOLLIDER_H_
#define _SPHERECOLLIDER_H_
#include "Collider.h"
#include "Vector2.h"

class Vector2;
class GameObject;
class Transform;
class SphereCollider : public Collider
{
public:
	SphereCollider(GameObject *pGameobject, double radius = 1, Vector2 offset=Vector2::Zero());
	~SphereCollider();

	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;

	double GetRadius()const { return m_radius; }
	void SetRadius(const double &radius);


	Vector2 GetcircleCenter()const { return m_circleCenter; }
	

	friend class CheckCollider;
private:
	double m_radius;
	Vector2 m_offset;
	Vector2 m_circleCenter;
};
#endif
