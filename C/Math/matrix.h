#include <stdio.h>

int get_columns(float **array); 
	/* Returns the number of columns in the matrix  */
int get_rows(float **array);
int same_order_matrices(float **array1, float *array2);
float** matrix_sum(float **array1, float **array2);
float** matrix_scalar_product(float **array, int scalar);
float** matrix_transposition(float **array);
float** matrix_product(float **array1, float **array2);
