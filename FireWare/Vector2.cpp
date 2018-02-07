#include "Vector2.h"
#include <SDL.h>

#define PI 3.14159265
Vector2 Vector2::m_right = Vector2(1, 0);
Vector2 Vector2::m_left = Vector2(-1, 0);
Vector2 Vector2::m_up = Vector2(0, 1);
Vector2 Vector2::m_down = Vector2(0, -1);
Vector2 Vector2::m_zero = Vector2(0, 0);

Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
}


Vector2::Vector2(double newX, double newY)
{
	m_x = newX;
	m_y = newY;
}

Vector2::~Vector2()
{

}

void Vector2::SetNew(double x, double y)
{
	m_x = x;
	m_y = y;
}

Vector2& Vector2::operator=(const Vector2 &v1)
{
	m_x = v1.m_x;
	m_y = v1.m_y;
	return *this;
}

Vector2 & Vector2::operator=(Vector2 *pV1)
{
	m_x = pV1->m_x;
	m_y = pV1->m_y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2 &v1)
{
	m_x += v1.m_x;
	m_y += v1.m_y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2 &v1)
{
	m_x -= v1.m_x;
	m_y -= v1.m_y;
	return *this;
}

Vector2 & Vector2::operator*=(const double &factor)
{
	m_x *= factor;
	m_y *= factor;
	return *this;
}

Vector2 & Vector2::operator/=(const double & factor)
{
	double tmp = 1 / factor;
	m_x *= tmp;
	m_y *= tmp;
	return *this;
}

Vector2 Vector2::normalize() const
{
	double k = 1 / sqrt(m_x*m_x + m_y*m_y);
	return Vector2(m_x*k, m_y*k);
}

void Vector2::RotByAng(const double angle)
{
	double length = Vector2::Length(*this);
	Vector2 newV = RotByVAng(*this, angle);
	this->SetNew(newV.X()*length, newV.Y()*length);
}

double Vector2::Distance(const Vector2 &v1, const Vector2 &v2) 
{
	Vector2 a(0, 1);
	Vector2 b(1, 0);
	double c = Vector2::Cross(a, b);

	Vector2 tmp = v1 - v2;
	return sqrt(tmp.m_x*tmp.m_x + tmp.m_y*tmp.m_y);
}

double Vector2::Length(const Vector2 & v1) 
{
	return sqrt(v1.m_x * v1.m_x + v1.m_y * v1.m_y);
}

//+1 same direction -1 opsite direction
double Vector2::Dot(const Vector2 & v1, const Vector2 & v2) 
{
    Vector2 temp1 = v1.normalize();
    Vector2 temp2 = v2.normalize();
    return temp1.m_x*temp2.m_x + temp1.m_y*temp2.m_y;
}

//if v2 is on the right of v1 retuen value less the 0, or bigger than 0
double Vector2::Cross(const Vector2 & v1, const Vector2 & v2) 
{
	return v1.m_x*v2.m_y - v2.m_x *v1.m_y;
}

double Vector2::Cross(const Vector2 & v1, const Vector2 & v2, const Vector2 & v3)
{
	Vector2 tmpV_1 = v2 - v1;
	Vector2 tmpV_2 = v3 - v1;
	return Cross(tmpV_1, tmpV_2);
}

double Vector2::Angle(const Vector2 &v1, const Vector2 &v2) 
{
	double dis1 = Length(v1); 
	double dis2 = Length(v2);
	double d = v1.m_x*v2.m_x + v1.m_y*v2.m_y;
	return acos(d / (dis1*dis2)) / PI * 180;
}

bool Vector2::IntersectionTwoVectors(const Vector2 & v1_1, const Vector2 & v1_2, const Vector2 & v2_1, const Vector2 & v2_2)
{
	
	if (v1_1 == v2_1 || v1_1 == v2_2 || v1_2 == v2_1 || v1_2 == v2_2)
		return true;
	if (PointOnLine(v1_1, v1_2, v2_1))  return true;
	if (PointOnLine(v1_1, v1_2, v2_2))  return true;
	if (PointOnLine(v2_1, v2_2, v1_1))  return true;
	if (PointOnLine(v2_1, v2_2, v1_2))  return true;

	double rl1_10 = Vector2::Cross(v1_1, v1_2, v2_1);
	double rl1_20 = Vector2::Cross(v1_1, v1_2, v2_2);
	if (rl1_10 > 0 && rl1_20 > 0)
	{
		return false;
	}
	if (rl1_10 < 0 && rl1_20 < 0)
	{
		return false;
	}
	
	double rl2_1 = Vector2::Cross(v2_1, v2_2, v1_1);
	double rl2_2 = Vector2::Cross(v2_1, v2_2, v1_2);
	if (rl2_1 > 0 && rl2_2 > 0)
	{
		return false;
	}
	if (rl2_1 < 0 && rl2_2 < 0)
	{
		return false;
	}

	if (rl1_10 == rl1_20 && rl1_10 == 0)
	{
		if (rl2_1 == rl2_2 &&  rl2_1 == 0)
		{
			return false;
		}
	}
	return true;
}

bool Vector2::PointOnLine(const Vector2 & v1_1, const Vector2 & v1_2, const Vector2 & v2)
{
	Vector2 tmp = v1_2 - v1_1;
	Vector2 tmpPoint = v2 - v1_1;
	if (tmp.m_x == 0)
	{
		if (tmpPoint.m_x != 0)
		{
			return false;
		}
		if (tmp.m_y > 0)
		{
			if (tmpPoint.m_y > 0 && tmpPoint.m_y < tmp.m_y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (tmp.m_y < 0)
		{
			if (tmpPoint.m_y < 0 && tmpPoint.m_y > tmp.m_y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (tmp.m_y == 0)
		{
			if (tmpPoint.m_y == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}

	if (tmp.m_y == 0)
	{
		if (tmpPoint.m_y != 0)
		{
			return false;
		}
		if (tmp.m_x > 0)
		{
			if (tmpPoint.m_x > 0 && tmpPoint.m_x < tmp.m_x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (tmp.m_x < 0)
		{
			if (tmpPoint.m_x < 0 && tmpPoint.m_x > tmp.m_x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	if (tmp.m_x / tmp.m_y == tmpPoint.m_x / tmpPoint.m_y)
	{
		return true;
	}
	return false;
}

bool Vector2::PointInQuadrangle(const Vector2 & v1, const Vector2 & v2, const Vector2 & v3, const Vector2 & v4, const Vector2 point)
{
	double d1 = Vector2::Cross(v1, v2, point);
	if (d1 > 0)return false;

	double d2 = Vector2::Cross(v2, v3, point);
	if (d2 > 0)return false;

	double d3 = Vector2::Cross(v3, v4, point);
	if (d3 > 0)return false;

	double d4 = Vector2::Cross(v4, v1, point);
	if (d4 > 0)return false;

	return true;
}

