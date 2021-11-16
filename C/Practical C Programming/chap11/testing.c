#include <stdio.h>

int main() {
	int number = 0x80;
	printf("%x and %x\n", number, (number>>1));
}
