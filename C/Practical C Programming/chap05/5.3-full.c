#include <string.h>
#include <stdio.h>

char first[100];
char last[100];
char full_name[200];

int main(){
/* 	Static input, previously defined: 
	strcpy(first, "Steve");
	strcpy(last, "Oualline");
*/
	printf("Enter first name.\n"); /* Dynamic input, defined in run-time: */
	fgets(first, sizeof(first), stdin);
	first[strlen(first) - 1] = '\0'; /* Trim off the break line character */

	printf("Enter last name.\n");
	fgets(last, sizeof(last), stdin);
	last[strlen(last) - 1] = '\0'; /* Trim off the break line character */

	strcpy(full_name, first);
	strcat(full_name, " ");
	strcat(full_name, last);

	printf("The full name is %s\n", full_name);
	return(0);
}
