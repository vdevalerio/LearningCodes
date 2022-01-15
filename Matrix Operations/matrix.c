#include <stdio.h>
#include "matrix.h"

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
	size_t upper_row_index, lower_row_index;
	for(size_t i = 0; i < rows; ++i)
	{
		upper_row_index = get_row_pivot_index(rows, columns, array, i);
		for(size_t j = i; j < rows; ++j)
		{
			lower_row_index = get_row_pivot_index(rows, columns, array, j);
			if(upper_row_index > lower_row_index)
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

	for(size_t i = 0; i < (columns - 1); ++i)
	{
		for(size_t j = i; j < (rows - 1); ++j)
		{
			float factor = get_elimination_factor(rows, columns, array, j + 1, i, i);
			factor *= -1;
			float auxiliary_row[columns];
			float *auxiliary_pointer = &auxiliary_row[0];
			multiply_row_by_nonzero(rows, columns, array, i, factor,  auxiliary_pointer);	
			add_vector_into_row(rows, columns, array, auxiliary_pointer, j + 1);
		}
	}
}
