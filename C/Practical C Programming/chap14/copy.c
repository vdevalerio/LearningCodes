#include <stdio.h>
#include <stdlib.h>

#define WRITE

const char FILE_NAME[] = "name.txt";

int main () {
	int count = 0;		/* Number of characters seen */
	FILE *name_file;	/* Input file  */
	/* Character or EOF flag from input */
	int ch;

	name_file = fopen (FILE_NAME, "w");
	if (name_file == NULL) {
		printf("Cannot open %s\n", FILE_NAME);
		exit (8);
	}
#ifdef READ
	while (1) {
		ch = fgetc(name_file);
		if (ch == EOF)
			break;
		++count;
	}
	printf("Number of characters in %s is %d\n", FILE_NAME, count);
#endif /* READ */
#ifdef WRITE
//	fputc(97, name_file);
	fputs("Marcos Valerio de Carvalho Cardoso Junior", name_file);
#endif /* WRITE */
	fclose(name_file);
	return (0);
}
