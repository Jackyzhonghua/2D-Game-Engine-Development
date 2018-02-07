#include "BoxCollider.h"
#include "GameObject.h"
#include "Transform.h"
#include "SDL.h"



BoxCollider::BoxCollider(GameObject *pGameobject, const double offsetLeft, const double offsetUp, const double offsetRight, const double offsetDown)
	:Collider(pGameobject, "BoxCollider", k_boxCollider)
{
	m_offsets[0] = -offsetLeft;
	m_offsets[1] = -offsetUp;
	m_offsets[2] = offsetRight;
	m_offsets[3] = offsetDown;

	m_pSelfGameObject->AddComponent(this);
	m_pSelfTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_centerPoint = &m_pSelfTransform->GetPosition();
	m_rotation = m_pSelfTransform->GetRotation();
	

	InitByScal();

	for (int i = 0; i < 4; ++i)
	{
		m_points.push_back(new Vector2((*m_pointOrigin[i]) + (*m_centerPoint)));
	}
	a = 0;
} 


BoxCollider::~BoxCollider()
{
	for(auto v: m_points)
	{
		delete v;
		v = nullptr;
	}
	for (auto v : m_pointOrigin)
	{
		delete v;
		v = nullptr;
	}
}

void BoxCollider::Awake()
{

}

void BoxCollider::Start()
{
}

void BoxCollider::Update()
{
	m_centerPoint = &m_pSelfTransform->GetPosition();

	if (m_rotation != m_pSelfTransform->GetRotation())
	{
		for (int i = 0; i < 4; ++i)
		{
			m_pAnglesReal[i] = m_pAngles[i] + m_pSelfTransform->GetRotation();

			if (m_pAnglesReal[i] > 360)
				m_pAnglesReal[i] -= 360;
			if (m_pAnglesReal[i] < 0)
				m_pAnglesReal[i] += 360;

				m_pointOrigin[i]->SetNew(Mathf::m_cos(m_pAnglesReal[i]) * m_pLengths[i], -Mathf::m_sin(m_pAnglesReal[i]) * m_pLengths[i]);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		m_points[i]->SetNew(m_pointOrigin[i]->X() + m_centerPoint->X(), m_pointOrigin[i]->Y() + m_centerPoint->Y());
	}
	m_rotation = m_pSelfTransform->GetRotation();
}

void BoxCollider::InitByScal()
{
	for (int i = 0; i < 4; ++i)
	{
		double offset1 = m_offsets[i];
		double offset2 = 0;
		if (i == 3)
			offset2 = m_offsets[0];
		else
		{
			offset2 = m_offsets[i + 1];
		}

		Vector2 *pointi = new Vector2(offset1 * m_pSelfTransform->GetScale().X(), offset2 * m_pSelfTransform->GetScale().Y());
		m_pLengths[i] = Vector2::Distance(Vector2::Zero(), *pointi);
		Vector2 last(pointi->X(), -pointi->Y());
		Vector2 dir_0 = last - Vector2::Zero();
		m_pAngles[i] = Vector2::Angle(Vector2::Right(), dir_0);
		double lr = Vector2::Cross(Vector2::Right(), dir_0);
		if (lr > 0)
		{
			m_pAngles[i] = 360 - m_pAngles[i];
		}
		m_pointOrigin.push_back(pointi);
	}
}
