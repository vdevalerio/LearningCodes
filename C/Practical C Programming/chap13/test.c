#include <stdio.h>

#define TEST1

#ifdef TEST1
int main() {
	int thing;
	int *thing_ptr;

	thing = 4;
	thing_ptr = &thing;

	printf("The value of thing is: %d.\n", thing);
	printf("The value of thing is: %d.\n", *thing_ptr);

	*thing_ptr = 5;

	printf("The value of thing is: %d.\n", thing);
	printf("The value of thing is: %d.\n", *thing_ptr);

	return (0);
}

#endif /* TEST1 */
