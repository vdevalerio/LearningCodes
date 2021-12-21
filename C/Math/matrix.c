#include <stdio.h>
#include <stdarg.h>
#include "matrix.h"

void print_matrix(int row, int column, float *array) {
	for(size_t i = 0; i < row; ++i) {
		printf("| ");
		for(size_t j = 0; j < column; ++j) {
			printf("%.1f ", array[j + (column * i)]);
		}
		printf("|\n");
	}
}
