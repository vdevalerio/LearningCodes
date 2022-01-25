#include <math.h>
#include "financial.h"

float simple_interest(float current, float rate, int period)
{
	float future = current * (1.0 + rate * period);
	return future;
}

float compound_interest(float current, float rate, int period)
{
	float value = pow((1.0 + rate), period);
	float future = current * value;
	return future;
}

float future_value(float current, float rate, int period, int type)
{
	if(type == 0)
	{
		return simple_interest(current, rate, period);
	}
	else if(type == 1)
	{
		return compound_interest(current, rate, period);
	}
	else
	{
		return -1;
	}
}
