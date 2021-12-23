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

int get_row_pivot_index(int rows, int columns, float *array, int target_row)
{
	for(size_t i = 0; i < columns; ++i)
	{
		if(array[(target_row * columns) + i] != 0)
			return (i + 1);
	}
	return -1;
}

void swap_rows(int rows, int columns, float* array,\
				int row1, int row2)
{
	float temporary;
		
	for(size_t j = 0; j < columns; ++j) {
		temporary = array[(row1 * columns) + j];
		array[(row1 * columns) + j] = \
			array[(row2 * columns) + j];
		array[(row2 * columns) + j] = temporary;
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

void multiply_row_by_nonzero(int rows, int columns, float *array,\
						int target_row, float factor, float *multiplied_row)
{
	for(size_t i = 0; i < columns; ++i)
	{
		multiplied_row[i] = array[(target_row * columns) + i] * factor;
	}
}

void add_row1_into_row2(int rows, int columns, float *array, int row1, int row2)
{
	for(size_t i = 0; i < columns; ++i)
	{
		array[(row2 * columns) + i] += array[(row1 * columns) + i];
	}
}

void add_vector_into_row(int rows, int columns, float *array,\
				float *vector, int row)
{
	for(size_t i = 0; i < columns; ++i)
	{
		array[(row * columns) + i] += vector[i];
	}

}

float get_elimination_factor(int rows, int columns, float *array,\
					int row1, int row2, int column)
{
	float number1, number2, factor;
	number1 = array[(row1 * columns) + column];
	number2 = array[(row2 * columns) + column];
	factor = number1 / number2;

	return factor;
}

void gaussian_elimination(int rows, int columns, float *array)
{
	raise_leftmost_pivot_rows(rows, columns, array);
	float factor = get_elimination_factor(rows, columns, array, 1, 0, 0);
	float auxiliary_row[columns];
	float *auxiliary_pointer = &auxiliary_row[0];
	multiply_row_by_nonzero(rows, columns, array, 1, factor, auxiliary_pointer);
	add_vector_into_row(rows, columns, array, auxiliary_pointer, 1);
}
