#ifndef _COLLIDER_H_
#define _COLLIDER_H_
class Collider;
#include "Componentbehavior.h"

class Transform;
class GameObject;
enum ColliderType
{
	k_boxCollider,
	k_sphereCollider,
	k_pointCollider
};

class Collider: public Componentbehavior
{
public:
	Collider(GameObject *pGameobject, std::string name, ColliderType colliderType);
	~Collider();

	virtual void Awake() override {}
	virtual void Start() override {}
	virtual void Update() override {}
	 

	ColliderType GetCollideType() { return m_colliderType; }
	int GetLayer()const { return m_layer; }
	void SetLayer(int layer);


protected:
	ColliderType m_colliderType;
	Transform* m_pSelfTransform;
	int m_layer;
};
































#endif