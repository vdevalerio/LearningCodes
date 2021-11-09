#include <stdio.h>

char line[100];
float height;
float width;
float area;

int main(){
	printf("Enter [width] [height]: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f %f", &width, &height);

	area = (width * height) / 2;

	printf("The area is %.2f.\n", area);

	return(0);
}
