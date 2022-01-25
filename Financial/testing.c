#include <stdio.h>
#include "financial.c"

int main ()
{
	float future, current, rate;
	int period, type;
	while(1)
	{
		printf("Current\tRate\tPeriod\tType\n");
		scanf("%f %f %d %d", &current, &rate, &period, &type);
		
		future = future_value(current, rate, period, type);
		printf("Future Value: $%.2f\n", future);
	}

	return (0);
}
