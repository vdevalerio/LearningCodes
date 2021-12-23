#include <stdio.h>

void print_matrix(int, int, float*);
int get_row_pivot_index(int, int, float*, int);
/* 	return row pivot index if row does not consist
 * 		of only zeros
 * 	return -1 if the row consist of only zeros
 */ 	
void swap_rows(int, int, float*, int, int);
void raise_leftmost_pivot_rows(int, int, float*);

/* 	TODOs
 * 		multiply row by nonzero
 * 		adding a multiple of one row
 * 			to another row
 * 		gaussian elimination itself
 */
