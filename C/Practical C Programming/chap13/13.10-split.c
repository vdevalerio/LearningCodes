#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/************************************************************
 * my_strchr -- Finds a character in a string.				*
 * 		Duplicate of a standard library function,			*
 * 		put here for illustrative purposes					*
 *															*
 * Parameters												*
 * 		string_ptr 	-- String to look through.				*
 * 		find 		-- Character to find.					*
 * 															*
 * Returns													*
 * 		pointer to 1st occurrence of character				*
 * 		in string or NULL for error.						*
 ************************************************************/
char *my_strchr (char *string_ptr, char find) {
	while (*string_ptr != find) {
		if (*string_ptr == '\0') {
			return (NULL);
		}
		++string_ptr;
	}
	return (string_ptr);
}
int main () {
	char line[80];
	char *first_ptr;
	char *last_prt;

	fgets(line, sizeof(line), stdin);

	line[strlen(line) - 1] = '\0';

	last_prt = line;
	first_ptr = my_strchr(line, '/');

	/* Check for an error */
	if (first_ptr == NULL) {
		fprintf(stderr,
				"Error: Unable to find slash in %s\n", line);
		exit(8);
	}

	*first_ptr = '\0';
	++first_ptr;

	printf("First: %s Last: %s\n", first_ptr, last_prt);
	return 0;
}
