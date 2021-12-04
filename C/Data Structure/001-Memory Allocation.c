/**************************************************** * malloc 	- Alloc memory							*
 * free		- Free allocated memory					*
 ****************************************************/
#include <stdio.h>
#include <stdlib.h>

int main () {

	/*	Static Allocation 	*/
	const int max_size = 1000;
	typedef struct client_id {
		char name[100];
		char gender;
		int age;
	} client;
	struct client_id client_list[max_size];

	/*	Dynamic Allocation 	*/
	int *v;
	v = (int *) malloc(max_size * sizeof(client));
	if (v == NULL) {
		printf("Error\n");
	}
	free(v);
	return (0);
}
