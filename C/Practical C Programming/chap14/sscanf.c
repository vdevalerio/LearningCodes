#include <stdio.h>

int main () {
	char line[100];
	int count, total;
	int scan_count;

	fgets(line, sizeof(line), stdin);
	scan_count = sscanf(line, "%d %d", &count, &total);

	switch (scan_count) {
		case EOF:
		case 0:
			printf("Didn't find any number\n");
			break;
		case 1:
			printf("Found 'count' (%d), but not 'total' (%d)\n", count, total);
			break;
		case 2:
			printf("Found both 'count' and 'total' (%d)\n", count, total);
			break;
		default:
			printf("This should not be possible\n");
			break;
	}
	return (0);
}
