#include <stdio.h>
#include <malloc.h>
#include "matrix.c"

#define ROWS 3
#define COLUMNS 3

/* List with all TESTING_* variables:
 *  TESTING_SWAP
 *  TESTING_PIVOT
 *  TESTING_RAISE_LEFTMOST_PIVOT
 *  TESTING_MULTIPLY_ROW_BY_NONZERO
 *  TESTING_ADD_ROW1_INTO_ROW2
 *  TESTING_ADD_VECTOR_INTO_ROW
 *  TESTING_ELIMINATION_FACTOR
 *  TESTING_GAUSSIAN_ELIMINATION
 */
#define TESTING_GAUSSIAN_ELIMINATION

int main ()
{
	float array[ROWS][COLUMNS] = {
			{4, 5, 5},
			{5, 5, 5},
			{2, 1, 1} };
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

#ifdef TESTING_RAISE_LEFTMOST_PIVOT
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	raise_leftmost_pivot_rows(ROWS, COLUMNS, array_pointer);

	printf("Raised Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
#endif /* TESTING_RAISE_LEFTMOST_PIVOT */

#ifdef TESTING_MULTIPLY_ROW_BY_NONZERO
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	float multiplied_row[COLUMNS];
	float *multiplied_pointer;
	multiplied_pointer = &multiplied_row[0];

	printf("Multiplied row: ");
	multiply_row_by_nonzero(ROWS, COLUMNS, array_pointer, 2,\
							3.5, multiplied_pointer);
	for(int i = 0; i < COLUMNS; ++i)
	{
		printf("%.1f ", multiplied_row[i]);
	}
	printf("\n");

#endif /* TESTING_MULTIPLY_ROW_BY_NONZERO */

#ifdef TESTING_ADD_ROW1_INTO_ROW2
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	add_row1_into_row2(ROWS, COLUMNS, array_pointer, 2, 0);

	printf("Added Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

#endif /* TESTING_ADD_ROW1_INTO_ROW2 */

#ifdef TESTING_ADD_VECTOR_INTO_ROW
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	float vector[COLUMNS] = {1, 1, 1};
	float *vector_pointer = &vector[0];

	add_vector_into_row(ROWS, COLUMNS, array_pointer, vector_pointer, 0);

	printf("Added Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

#endif /* TESTING_ADD_ROW1_INTO_ROW2 */
#ifdef TESTING_ELIMINATION_FACTOR
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
	
	float factor = get_elimination_factor(ROWS,\
			COLUMNS, array_pointer, 2, 1, 0);
	printf("%.1f\n", factor);


#endif /* TESTING_ELIMINATION_FACTOR */

#ifdef TESTING_GAUSSIAN_ELIMINATION
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	gaussian_elimination(ROWS, COLUMNS, array_pointer);

	printf("Resultant Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
#endif /* TESTING_GAUSSIAN_ELIMINATION  */
	return (0);
}
