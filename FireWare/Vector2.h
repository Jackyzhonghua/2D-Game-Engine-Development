#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <math.h>
#include "Mathf.h"


class Vector2
{
public:
	Vector2();
	//Vector2(Vector2 &v1);
	Vector2(double newX, double newY);
	~Vector2();

	double X() const { return m_x; }
	double Y() const { return m_y; }
	void SetNew(double x, double y);
	
	Vector2& operator=(const Vector2 &v1);
	Vector2& operator=(Vector2 *pV1);
	Vector2& operator+=(const Vector2 &v1);
	Vector2& operator-=(const Vector2 &v1);
	Vector2& operator*=(const double &factor);
	Vector2& operator/=(const double &factor);

	Vector2 normalize() const;

	void RotByAng(const double angle);

	static double Distance(const Vector2 &v1, const Vector2 &v2);
	static double Length(const Vector2 &v1);
	static double Dot(const Vector2 &v1, const Vector2 &v2);
	static double Cross(const Vector2 &v1, const Vector2 &v2);
	//adjuge v3 v1 is on the right or left of v2 v1
	static double Cross(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3);
	static double Angle(const Vector2 &v1, const Vector2 &v2);

	static bool IntersectionTwoVectors(const Vector2 &v1_1, const Vector2 &v1_2, const Vector2 &v2_1, const Vector2 &v2_2);
	static bool PointOnLine(const Vector2 &v1_1, const Vector2 &v1_2, const Vector2 &v2);
	static bool PointInQuadrangle(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, const Vector2 point);


	static Vector2 Right() { return m_right; } 
	static Vector2 Left() { return m_left; }
	static Vector2 Up() { return m_right; }
	static Vector2 Down() { return m_right; }
	static Vector2 Zero() { return m_zero; }


private:
	static Vector2 m_right;
	static Vector2 m_left;
	static Vector2 m_up;
	static Vector2 m_down;
	static Vector2 m_zero;

	double m_x;
	double m_y;

	friend Vector2 operator+(const Vector2 v1, const Vector2 v2);
	friend Vector2 operator-(const Vector2 &v1, const Vector2 &v2);
	friend Vector2 operator*(const Vector2 &v1, const double &factor);
	friend Vector2 operator*(const Vector2 &v1, const Vector2 &v2);
	friend Vector2 operator/(const Vector2 &v1, const double &factor);
	friend Vector2 operator/(const Vector2 &v1, const Vector2 &v2);
	friend bool operator==(const Vector2 &v1, const Vector2 &v2);
	friend bool operator!=(const Vector2 &v1, const Vector2 &v2);
	friend Vector2 RotByVAng(const Vector2 &v1, const double angle);
};


inline Vector2 operator+(const Vector2 v1, const Vector2 v2)
{
	return Vector2(v1.m_x + v2.m_x, v1.m_y + v2.m_y);
}

inline Vector2 operator-(const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.m_x - v2.m_x, v1.m_y - v2.m_y);
}

inline Vector2 operator*(const Vector2 &v1, const double &factor)
{
	return Vector2(v1.m_x * factor, v1.m_y * factor);
}

inline Vector2 operator*(const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.m_x * v2.m_x, v1.m_y * v2.m_y);
}

inline Vector2 operator/(const Vector2 &v1, const double &factor)
{
	return Vector2(v1.m_x / factor, v1.m_y / factor);
}

inline Vector2 operator/(const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.m_x / v2.m_x, v1.m_y / v2.m_y);
}

inline bool operator==(const Vector2 &v1, const Vector2 &v2)
{
	if (v1.m_x == v2.m_x && v1.m_y == v2.m_y)
	{
		return true;
	}
	return false;
}

inline bool operator!=(const Vector2 &v1, const Vector2 &v2)
{
	return !(v1 == v2);
}

inline Vector2 RotByVAng(const Vector2 &v1, const double angle)
{
	double length = Vector2::Length(v1);
	double vAngle = Vector2::Angle(Vector2::Right(), v1);
	double c = Vector2::Cross(Vector2::Right(), v1);
	if (c > 0)
	{
		vAngle = 360 - vAngle;
	}
	double newAngle = vAngle + angle;
	if (newAngle < 0)
	{
		newAngle = 360 + newAngle;
	}
	Vector2 newV(Mathf::m_cos(newAngle), Mathf::m_sin(newAngle));
	return newV;
}
#endif





