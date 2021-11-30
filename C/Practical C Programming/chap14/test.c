#include <stdio.h>
#include <stdlib.h>

FILE *in_file;

int main () {
	in_file = fopen("name.txt", "r");
	if (in_file == NULL) {
		fprintf (stderr, "Error: Unable to input file.\n");
		exit (8);
	}
	return (0);
}
