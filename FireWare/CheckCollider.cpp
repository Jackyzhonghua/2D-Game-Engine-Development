#include "CheckCollider.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "PointCollider.h"
#include <SDL.h>

bool CheckCollider::CheckColliders(BoxCollider * pBoxCollider01, BoxCollider * pBoxCollider02)
{
	Vector2 v1_1, v1_2, v2_1, v2_2;
	v1_1 = v1_2 = v2_1 = v2_2 = Vector2::Zero();
	for (unsigned int i = 0; i < pBoxCollider01->m_points.size(); ++i)
	{
		for (unsigned int j = 0; j < pBoxCollider02->m_points.size(); ++j)
		{
			v1_1 = pBoxCollider01->m_points[i];
			if (i == pBoxCollider01->m_points.size() - 1)
				v1_2 = pBoxCollider01->m_points[0];
			else
				v1_2 = pBoxCollider01->m_points[i + 1];
		
			v2_1 = pBoxCollider02->m_points[j];
			if (j == pBoxCollider02->m_points.size() - 1)
				v2_2 = pBoxCollider02->m_points[0];
			else
				v2_2 = pBoxCollider02->m_points[j + 1];

			if (Vector2::IntersectionTwoVectors(v1_1, v1_2, v2_1, v2_2))
			{
				return true;
			}
			
		}
		if (Vector2::PointInQuadrangle(*pBoxCollider02->m_points[0], *pBoxCollider02->m_points[1], *pBoxCollider02->m_points[2], *pBoxCollider02->m_points[3], *pBoxCollider01->m_points[i]))
			return true;
		if (Vector2::PointInQuadrangle(*pBoxCollider01->m_points[0], *pBoxCollider01->m_points[1], *pBoxCollider01->m_points[2], *pBoxCollider01->m_points[3], *pBoxCollider02->m_points[i]))
			return true;
	}
	return false; 
}

bool CheckCollider::CheckColliders(BoxCollider * pBoxCollider, SphereCollider * pSphereCollider)
{

	Vector2 v1, v2, vS;
	v1 = v2 = vS = Vector2::Zero();
	for (unsigned int i = 0; i < pBoxCollider->m_points.size(); ++i)
	{
		v1 = pBoxCollider->m_points[i];
		if (i == pBoxCollider->m_points.size() - 1)
			v2 = pBoxCollider->m_points[0];
		else
			v2 = pBoxCollider->m_points[i + 1];
		
		vS = pSphereCollider->m_circleCenter;

		//check each boxcollider's point is in spherecollider
		double dis = Vector2::Distance(v1, vS);
		if (dis < pSphereCollider->m_radius)
			return true;


		Vector2 v1v2 = v2 - v1;
		//get angle of one boxcollider edge and right direction
		double angle = Vector2::Angle(v1v2, Vector2::Right());
		double lr = Vector2::Cross(v1v2, Vector2::Right());
		if (lr < 0)
		{
			angle = 360 - angle;
		}

		//get vertical line two  angles of the boxcollider edge
		double angleSphere1 = angle - 90;
		if (angleSphere1 < 0)
		{
			angleSphere1 = 360 + angleSphere1;
		}
		double angleSphere2 = 0;
		if (angleSphere1 > 180)
		{
			angleSphere2 = angleSphere1 - 180;
		}
		else
		{
			angleSphere2 = angleSphere1 + 180;
		}

		//get two points of vertical dirction accross spherecollider center
		Vector2 spherePoint1(Mathf::m_cos(angleSphere1), Mathf::m_sin(angleSphere1));

		spherePoint1 = spherePoint1 * pSphereCollider->m_radius + pSphereCollider->m_circleCenter;

		Vector2 spherePoint2(Mathf::m_cos(angleSphere2), Mathf::m_sin(angleSphere2));

		spherePoint2 = spherePoint2*pSphereCollider->m_radius + pSphereCollider->m_circleCenter;

		//check is the two points intersect with the boxcollider edge
		if (Vector2::IntersectionTwoVectors(v1, v2, spherePoint1, spherePoint2))
			return true;
	}
	return false;
}

bool CheckCollider::CheckColliders(BoxCollider * pBoxCollider, PointCollider * pPointCollider)
{
	if (Vector2::PointInQuadrangle(*pBoxCollider->m_points[0], *pBoxCollider->m_points[1], *pBoxCollider->m_points[2], *pBoxCollider->m_points[3], pPointCollider->m_point))
		return true;
	return false;
}



bool CheckCollider::CheckColliders(SphereCollider * pSphereCollider01, SphereCollider * pSphereCollider02)
{
	double disOfSpheresRadius = pSphereCollider01->m_radius + pSphereCollider02->m_radius;
	double disOfSpheres = Vector2::Distance(pSphereCollider01->m_circleCenter, pSphereCollider02->m_circleCenter);
	
	if (disOfSpheres < disOfSpheresRadius)
	{
		return true;
	}
	
	return false;
}

bool CheckCollider::CheckColliders(SphereCollider * pSphereCollider, BoxCollider * pBoxCollider)
{
	return CheckColliders(pBoxCollider, pSphereCollider);
}

bool CheckCollider::CheckColliders(SphereCollider * pSphereCollider, PointCollider * pPointCollider)
{
	double disPointToSphere = Vector2::Distance(pSphereCollider->m_circleCenter, pPointCollider->m_point);

	if (disPointToSphere < pSphereCollider->m_radius)
		return true;
	return false;
}



bool CheckCollider::CheckColliders(PointCollider * pPointCollider01, PointCollider * pPointCollider02)
{
	if (pPointCollider01->m_point == pPointCollider02->m_point)
		return true;
	return false;
}

bool CheckCollider::CheckColliders(PointCollider * pPointCollider, BoxCollider * pBoxCollider)
{
	return CheckColliders(pBoxCollider, pPointCollider);
}

bool CheckCollider::CheckColliders(PointCollider * pPointCollider, SphereCollider * pSphereCollider)
{
	return CheckColliders(pSphereCollider, pPointCollider);
}


bool CheckCollider::CheckColliders(Collider * pCollider01, Collider * pCollider02)
{
	if (!pCollider01 || !pCollider02) return false;

	BoxCollider *pBoxCollider = nullptr;
	SphereCollider *pSphereCollider = nullptr;
	PointCollider *pPointCollider = nullptr;

	BoxCollider *pBoxCollider2 = nullptr;
	SphereCollider *pSphereCollider2 = nullptr;
	PointCollider *pPointCollider2 = nullptr;

	switch (pCollider01->GetCollideType())
	{
	case k_boxCollider:
		pBoxCollider = static_cast<BoxCollider*>(pCollider01);
		switch (pCollider02->GetCollideType())
		{
		case k_boxCollider:
			pBoxCollider2 = static_cast<BoxCollider*>(pCollider02);
			return CheckColliders(pBoxCollider, pBoxCollider2);
			break;
		case k_sphereCollider:
			pSphereCollider2 = static_cast<SphereCollider*>(pCollider02);
			return CheckColliders(pBoxCollider, pSphereCollider2);
			break;
		case k_pointCollider:
			pPointCollider2 = static_cast<PointCollider*>(pCollider02);
			return CheckColliders(pBoxCollider, pPointCollider2);
			break;
		}
		break;
	case k_sphereCollider:
		pSphereCollider = static_cast<SphereCollider*>(pCollider01);
		switch (pCollider02->GetCollideType())
		{
		case k_boxCollider:
			pBoxCollider2 = static_cast<BoxCollider*>(pCollider02);
			return CheckColliders(pSphereCollider, pBoxCollider2);
			break;
		case k_sphereCollider:
			pSphereCollider2 = static_cast<SphereCollider*>(pCollider02);
			return CheckColliders(pSphereCollider, pSphereCollider2);
			break;
		case k_pointCollider:
			pPointCollider2 = static_cast<PointCollider*>(pCollider02);
			return CheckColliders(pSphereCollider, pPointCollider2);
			break;
		}
		break;
	case k_pointCollider:
		pPointCollider = static_cast<PointCollider*>(pCollider01);
		switch (pCollider02->GetCollideType())
		{
		case k_boxCollider:
			pBoxCollider2 = static_cast<BoxCollider*>(pCollider02);
			return CheckColliders(pPointCollider, pBoxCollider2);
			break;
		case k_sphereCollider:
			pSphereCollider2 = static_cast<SphereCollider*>(pCollider02);
			return CheckColliders(pPointCollider, pSphereCollider2);
			break;
		case k_pointCollider:
			pPointCollider2 = static_cast<PointCollider*>(pCollider02);
			return CheckColliders(pPointCollider, pPointCollider2);
			break;
		}
		break;
	}

	return false;
}

