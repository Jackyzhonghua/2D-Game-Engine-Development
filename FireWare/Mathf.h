#ifndef _MATHF_H_
#define _MATHF_H_
#include <math.h>

#define PI 3.14159265
class Mathf
{
public:
	//for y
	static double m_sin(double angle)
	{
		while (angle>360)
		{
			angle -= 360;
		}
		if (angle == 0 || angle == 180)
		{
			return 0;
		}
		double result = sin(angle*PI / 180);
		return -result;
	}

	//for x
	static double m_cos(double angle)
	{
		while (angle>360)
		{
			angle -= 360;
		}
		if (angle == 90 || angle == 270)
		{
			return 0;
		}
		return cos(angle*PI / 180);
	}

	static double Abs(double value)
	{
		if (value < 0)
		{
			return -value;
		}
		return value;
	}
};
#endif 