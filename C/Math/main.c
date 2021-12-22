#include <stdio.h>
#include <malloc.h>
#include "matrix.c"

#define ROWS 3
#define COLUMNS 5

#define TESTING_PIVOT

int main ()
{
	float array[ROWS][COLUMNS] = {
			{1, 2, 3, 4, 5},
			{0, 0, 7, 8, 9},
			{0, 4, 5, 6, 7} };
	float *array_pointer = &array[0][0];
	
#ifdef TESTING_SWAP
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	swap_rows(ROWS, COLUMNS, array_pointer, 0, 2);

	printf("Swapped Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
#endif /* TESTING_SWAP */

#ifdef TESTING_PIVOT
	printf("Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
	for(size_t i = 0; i < ROWS; ++i)
	{
		int pivot = get_row_pivot_index(ROWS, COLUMNS, array_pointer, i);
		printf("%d\n", pivot);
	}
#endif /* TESTING_PIVOT */

	return (0);
}
