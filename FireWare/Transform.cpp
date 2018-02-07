#include "Transform.h"
#include "GameObject.h"
#include <SDL.h>

Transform::Transform():Componentbehavior(nullptr, "Tramsform", k_transform)
{
	m_position = Vector2::Zero();
	m_localPosition = Vector2::Zero();
	m_scale.SetNew(1, 1);
	m_localScale.SetNew(1, 1);
	m_rotation = 0.001;
	m_localRotation = 0.001;
	SetUpRight();
}

Transform::Transform(GameObject *pGameobject):Componentbehavior(pGameobject,"Tramsform",k_transform)
{
	m_position = Vector2::Zero();
	m_localPosition = Vector2::Zero();
	m_scale.SetNew(1, 1);
	m_localScale.SetNew(1, 1);
	m_rotation = 0.001;
	m_localRotation = 0.001;
	SetUpRight();
	pGameobject->SetTransform(this);
}


Transform::~Transform()
{
	for (auto c : m_childs)
	{
		c = nullptr;
	}
	m_pParent = nullptr;
	m_pRoot = nullptr;
}

void Transform::Awake()
{
}

void Transform::Start()
{
}

void Transform::Update()
{
	m_right.SetNew(Mathf::m_cos(m_rotation), Mathf::m_sin(m_rotation));
	SetWroldPRSByLocal();
	SetRotationByParent();
	if(m_pParent != nullptr)
		m_oldParentRotation = m_pParent->GetLocalRotation();

}


void Transform::SetEnable(bool bEnable)
{
	SDL_Log("Transform canot be disable");
}

void Transform::SetPosition(Vector2 newPosition)
{
	m_position = newPosition;
	SetLocalPRSByWorld();
}

void Transform::SetPosition(double const x, double const y)
{
	m_position.SetNew(x, y);
	SetLocalPRSByWorld();
}

void Transform::SetRotation(double angle)
{
	//double angleOffset = angle - m_rotation;
	m_rotation = angle;
	SetLocalPRSByWorld();
}

void Transform::SetScale(Vector2 newScal)
{
	m_scale = newScal;
	SetLocalPRSByWorld();
}

void Transform::SetScale(double x, double y)
{
	
	m_scale.SetNew(x, y);
	SetLocalPRSByWorld();
}

void Transform::SetLocalPosition(Vector2 newPosition)
{
	m_localPosition = newPosition;
	SetWroldPRSByLocal();
}

void Transform::SetLocalPosition(double x, double y)
{
	if (x == 0)
		x = 0.001;
	if (y == 0)
		y = 0.001;

	m_localPosition.SetNew(x, y);
	SetWroldPRSByLocal();
}

void Transform::SetLocalRotation(double angle)
{
	m_localRotation = angle;
	SetWroldPRSByLocal();
}

void Transform::SetLocalScale(Vector2 newScal)
{
	m_localScale = newScal;
	SetWroldPRSByLocal();
}

void Transform::SetLocalScale(double x, double y)
{
	m_localScale.SetNew(x, y);
	SetWroldPRSByLocal();
}

void Transform::TranslateLocal(const Vector2 dirction)
{
	double speed = Vector2::Length(dirction);
	Vector2 dir;
	if (m_pParent == nullptr)
	{
		dir = dirction.normalize();
	}
	else
	{
		double c = Vector2::Cross(Vector2::Right(), dirction);
		double angle = Vector2::Angle(m_pParent->Right(), dirction);
		if (c > 0)
		{
			angle = 360 - angle;
		}
		double realangle = (angle + m_rotation) > 360 ? (angle + m_rotation - 360) : (angle + m_rotation);
		dir = Vector2(Mathf::m_cos(realangle), Mathf::m_sin(realangle));
	}

	m_localPosition += dir*speed;
	//SetWroldPRSByLocal();
}

void Transform::Translate(const Vector2 dirction)
{
	m_position += dirction;
	 
	SetLocalPRSByWorld();
}

void Transform::Rotate(double angle)
{
	m_localRotation += angle;
	while (m_localRotation > 360)
	{
		m_localRotation -= 360;
	}
	while (m_localRotation < 0)
	{
		m_localRotation += 360;
	}
	SetWroldPRSByLocal();
}

void Transform::Scal(Vector2 scal)
{
	m_localScale += scal;
	SetWroldPRSByLocal();
}


void Transform::SetParent(Transform *parent)
{
	m_pParent = parent;
	parent->AddChild(this);
}

void Transform::AddChild(Transform *child)
{
	m_childs.push_back(child);
}

Transform* Transform::Find(std::string  name) const
{
	if (m_childs.size() <= 0) return nullptr;
	for (auto c : m_childs)
	{
		if (c->m_pSelfGameObject->GetName() == name)
		{
			return c;
		}
	}
	return nullptr;
}

Transform* Transform::GetChild(int index) const
{
	if (m_childs.size() <= 0 || (unsigned int)index >= m_childs.size())
	{
		throw "out of index";
		return nullptr;
	}
	return m_childs[index];
}


void Transform::SetLocalPRSByWorld()
{
	if (m_pParent != nullptr)
	{
		m_localPosition = (m_position - m_pParent->GetPosition())/ m_pParent->GetScale();
		m_localRotation = m_rotation - m_pParent->GetRotation();
		m_localScale = m_scale / m_pParent->GetScale();
	}
	else
	{
		m_localPosition = m_position;
		m_localRotation = m_rotation;
		m_localScale = m_scale;
	}
	SetUpRight();
}

void Transform::SetWroldPRSByLocal()
{
	if (m_pParent != nullptr)
	{
		m_position = m_pParent->GetPosition() + m_localPosition * m_pParent->GetScale();
		m_rotation = m_localRotation + m_pParent->GetRotation();
		m_scale = m_localScale * m_pParent->GetScale();
	}
	else
	{
		m_position = m_localPosition;
		m_rotation = m_localRotation;
		m_scale = m_localScale;
	}
	SetUpRight();
}

void Transform::SetUpRight()
{
	m_right = Vector2(Mathf::m_cos(m_rotation), Mathf::m_sin(m_rotation));
	double angle = m_rotation - 90;
	if (angle < 0)
		angle = 360 - angle;
	m_up = Vector2(Mathf::m_cos(angle), Mathf::m_sin(angle));
}

void Transform::ResetRotation()
{
	if (m_pParent != nullptr)
	{
		double angle = Vector2::Angle(Vector2::Right(), m_right);
		double c = Vector2::Cross(Vector2::Right(), m_right);
		if (c > 0)
		{
			angle = 360 - angle;
		}
		m_localRotation = m_pParent->GetRotation() - angle;
		while (m_localRotation > 360)
		{
			m_localRotation -= 360;
		}
		while (m_localRotation < 0)
		{
			m_localRotation += 360;
		}
	}
}

void Transform::SetRotationByParent()
{
	if (m_pParent == nullptr) return;
	double angleOffset = m_pParent->GetLocalRotation() - m_oldParentRotation;
	if (angleOffset == 0)
		return;
	double length = Vector2::Length(m_localPosition);
	this->m_localPosition = RotByVAng(this->m_localPosition, -angleOffset)*length;

}


