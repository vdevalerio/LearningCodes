#include <stdio.h>
#include <stdarg.h>
#include "matrix.h"

void print_matrix(int rows, int columns, float *array) {
	for(size_t i = 0; i < rows; ++i) {
		printf("| ");
		for(size_t j = 0; j < columns; ++j) {
			printf("%.1f ", array[j + (columns * i)]);
		}
		printf("|\n");
	}
}

void swap_rows(int rows, int columns, int upper_row,\
				int lower_row, float* array) {
	float temporary[columns];
		
	for(size_t j = 0; j < columns; ++j) {
		temporary[j] = array[(upper_row * columns) + j];
		array[(upper_row * columns) + j] = \
			array[(lower_row * columns) + j];
		array[(lower_row * columns) + j] = temporary[j];
	}
}
