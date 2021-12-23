#include <stdio.h>

void print_matrix(int rows, int columns, float* matrix);
int get_row_pivot_index(int rows, int columns, float* matrix, int target_row);
/* 	return row pivot index if row does not consist
 * 		of only zeros
 * 	return -1 if the row consist of only zeros
 */ 	
void swap_rows(int rows, int columns, float* matrix, int row1, int row2);
void raise_leftmost_pivot_rows(int rows, int columns, float* matrix);
void multiply_row_by_nonzero(int rows, int columns, float* matrix,\
						int target_row, float factor, float* auxiliary_row);

void add_row1_into_row2(int rows, int columns, float* matrix,\
						int row1, int row2);
void add_vector_into_row(int rows, int columns, float* matrix,\
						float* vector, int row);
float get_elimination_factor(int rows, int columns, float* matrix,\
					int row1, int row2, int column);
void gaussian_elimination(int rows, int columns, float* matrix);
