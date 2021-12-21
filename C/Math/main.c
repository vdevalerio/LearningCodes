#include <stdio.h>
#include <malloc.h>
#include "matrix.c"

int main () {
	int rows = 3;
	int columns = 5;
	float array[rows][columns] = {
			{1, 2, 3, 4, 5},
			{5, 6, 7, 8, 9},
			{3, 4, 5, 6, 7} };
	float *array_pointer = &array[0][0];

	print_matrix(rows, columns, array_pointer);
	return (0);
}
