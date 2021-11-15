#include <stdio.h>
#undef UNDEF

int main() {
#ifdef UNDEF
	printf("Print line 1.\n");
	printf("Print line 2.\n");
	printf("Print line 3.\n");
	printf("Print line 4.\n");
#endif /* UNDEF */
	printf("Print line 5.\n");
	printf("Print line 6.\n");
	printf("Print line 7.\n");
	printf("Print line 8.\n");
}
