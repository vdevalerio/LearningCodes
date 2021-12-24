#include <stdio.h>
#include "matrix_io.h"

void print_matrix(int rows, int columns, float *array)
{
	for(size_t i = 0; i < rows; ++i)
	{
		printf("|");
		for(size_t j = 0; j < columns; ++j)
		{
			float current = array[(columns * i) + j];
			if(current < 0)
			{
				printf("  %.3f", array[(columns * i) + j]);
			}
			else
			{
				printf("   %.3f", array[(columns * i) + j]);
			}

		}
		printf("   |\n");
	}
}
