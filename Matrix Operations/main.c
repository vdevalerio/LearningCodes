#include <stdio.h>
#include <malloc.h>
#include "matrix.c"
#include "matrix_io.c"

int main()
{
	char matrix_name[30];
	printf("Name your matrix:\n");
	scanf("%s", matrix_name);

	int rows, columns;
	printf("Input ROWS COLUMNS: \n");
	scanf("%d %d", &rows, &columns);

	float array[rows * columns];

	printf("Input elements:\n");
	for(size_t i = 0; i < rows * columns; ++i)
	{
		scanf("%f", &array[i]);
	}

	printf("Select an operation:\n");
	printf("1- Gaussian Elimination\n");
	printf("2- Exit\n");
	int option;
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			gaussian_elimination(rows, columns, &array[0]);
			print_matrix(rows, columns, &array[0]);
			break;
			
		case 2:
			printf("Exiting...\n");
			break;

		default:
			break;
	}
	return 0;
}
