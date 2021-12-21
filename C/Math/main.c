#include <stdio.h>
#include <malloc.h>
#include "matrix.c"

int main () {

	float array[3][5] = {
			{1, 2, 3, 4, 5},
			{5, 6, 7, 8, 9},
			{3, 4, 5, 6, 7} };
	float *array_pointer = &array[0][0];

//	printf("%.1f\n", array_pointer[5]);
	print_matrix(3, 5, array_pointer);
	return (0);
}
