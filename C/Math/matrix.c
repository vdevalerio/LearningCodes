#include <stdio.h>
#include <stdarg.h>
#include "matrix.h"

void print_matrix(int rows, int columns, float *array)
{
	for(size_t i = 0; i < rows; ++i)
	{
		printf("| ");
		for(size_t j = 0; j < columns; ++j)
		{
			printf("%.1f ", array[j + (columns * i)]);
		}
		printf("|\n");
	}
}

int get_row_pivot_index(int rows, int columns, float *array, int row)
{
	for(size_t i = 0; i < columns; ++i)
	{
		if(array[(row * columns) + i] != 0)
			return (i + 1);
	}
	return -1;
}

void swap_rows(int rows, int columns, float* array,\
				int upper_row, int lower_row)
{
	float temporary[columns];
		
	for(size_t j = 0; j < columns; ++j) {
		temporary[j] = array[(upper_row * columns) + j];
		array[(upper_row * columns) + j] = \
			array[(lower_row * columns) + j];
		array[(lower_row * columns) + j] = temporary[j];
	}
}

void raise_leftmost_pivot_rows(int rows, int columns, float *array)
{
	size_t bigger, smaller;
	for(size_t i = 0; i < rows; ++i)
	{
		bigger = get_row_pivot_index(rows, columns, array, i);
		for(size_t j = 0; j < rows; ++j)
		{
			smaller = get_row_pivot_index(rows, columns, array, j);
			if(bigger < smaller)
			{
				swap_rows(rows, columns, array, i, j);
			}
		}
	}
}
