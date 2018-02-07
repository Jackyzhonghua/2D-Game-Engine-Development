#include "Radom.h"
#include <stdlib.h>

int Radom::Range(int left, int right)
{
	if (right < left) return right;
	if (right >= 0)
	{
		int range = right - left;
		return (rand() % range + left);
	}
	else
	{
		int range = right - left;
		return (right - rand() % range);
	}
}