#include "SphereCollider.h"
#include "GameObject.h"
#include "Transform.h"
#include <SDL.h>




SphereCollider::SphereCollider(GameObject *pGameobject, double radius, Vector2 offset) :Collider(pGameobject, "SphereCollider", k_sphereCollider), m_radius(radius), m_offset(offset)
{
	m_pSelfTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pSelfGameObject->AddComponent(this);

	m_circleCenter = m_pSelfTransform->GetPosition() + m_offset;
	m_radius = radius;
}


SphereCollider::~SphereCollider()
{
}

void SphereCollider::Awake()
{

}

void SphereCollider::Start()
{
}

void SphereCollider::Update()
{
	m_circleCenter = m_pSelfTransform->GetPosition() + m_offset;
}

void SphereCollider::SetRadius(const double & radius)
{
	m_radius = radius;
}


