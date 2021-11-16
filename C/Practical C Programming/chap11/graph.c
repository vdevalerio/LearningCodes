#include <stdio.h>

#define X_SIZE 8 
#define Y_SIZE 8

char graphics[1][Y_SIZE];

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

int main() {
	int loc;
	void print_graphics(void);

	for(loc = 0; loc < X_SIZE; ++loc){
		SET_BIT(loc, loc);
	}
	print_graphics();
	return(0);
}

void print_graphics(void) {
	int x;
	int y;
	unsigned int bit;
	for(y = 0; y < Y_SIZE; ++y) {
		for(x = 0; x < X_SIZE; ++x) {
			for(bit = 0x80; bit > 0; bit = (bit >> 1)) {
				if((graphics[x][y] & bit) != 0)
					printf("X");
				else
					printf(".");
			}
		}
		printf("\n");
	}
}
