#include <stdio.h>

int main () {
	float array1[2][2] = { {1, 2}, {3, 4}};	
	float array2[2][2] = { {1, 2}, {3, 4}};	

	printf("%f\n", **array1);
	return (0);
}
