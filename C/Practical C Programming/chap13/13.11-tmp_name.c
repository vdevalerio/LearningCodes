#include <stdio.h>
#include <string.h>

char *tmp_name () {
	char name[30];
	static int sequence = 0;

	++sequence;

	strcpy(name, "tmp");

	name[3] = sequence + '0';
	name[4] = '\0';

	return name;
}

int main () {
	//tmp_name();
	printf("Name: %s\n", tmp_name());
	
	return 0;
}
