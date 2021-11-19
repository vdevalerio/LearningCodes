#include <stdio.h>

#define GOOD

#ifdef BAD
void copy_string (char *p, char *q){
	printf("Using BAD ...\n");
	while (*p++ = *q++);
}
#else
/********************************************************
 * copy_string -- Copies one string to another 			*
 * 														*
 * Parameters											*
 * 		dest 	-- Where to put the string				*
 * 		source 	-- Where to get it						*
 ********************************************************/
void copy_string (char *dest, char *source) {
	printf("Using GOOD ...\n");
	while (1) {
		*dest = *source;

		/* Exit if we copied the end of string */
		if (*dest == '\0')
			return;

		++dest;
		++source;
	}
}
#endif /* BAD */
int main() {
	char name1[] = "Koba";
	char name2[] = "VOID";
	printf("Name 1: %s\nName 2: %s\n", &name1, &name2);
	copy_string(name1, name2);
	printf("Name 1: %s\nName 2: %s\n", &name1, &name2);
	return 0;
}
