#include "Collider.h"
#include "GameObject.h"
#include "Transform.h"



Collider::Collider(GameObject *pGameobject, std::string name, ColliderType colliderType) : Componentbehavior(pGameobject, name, k_collider), m_colliderType(colliderType),m_layer(0)
{
	m_pSelfTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
}


Collider::~Collider()
{
	m_pSelfTransform = nullptr;
}

void Collider::SetLayer(int layer)
{
	m_layer = layer;
}
