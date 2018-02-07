#ifndef _POINTCOLLIDER_H_
#define _POINTCOLLIDER_H_
#include "Collider.h"
#include "Vector2.h"

class GameObject;
class Vector2;
class Transform;
class PointCollider : public Collider
{
public:
	PointCollider(GameObject *pGameobject);
	~PointCollider();

	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;

	friend class CheckCollider;
private:
	Vector2 m_point;
};
#endif

