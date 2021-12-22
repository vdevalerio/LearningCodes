#include <stdio.h>
#include <malloc.h>
#include "matrix.c"

#define ROWS 3
#define COLUMNS 5

int main ()
{
	float array[ROWS][COLUMNS] = {
			{1, 2, 3, 4, 5},
			{5, 6, 7, 8, 9},
			{3, 4, 5, 6, 7} };
	float *array_pointer = &array[0][0];
	
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	swap_rows(ROWS, COLUMNS, array_pointer, 0, 2);

	printf("Swapped Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
	
	return (0);
}
