#include <stdio.h>

const int ERROR = (1<<0);
const int FRAMING_ERROR = (1<<1);
const int PARITY_ERROR = (1<<2);
const int CARRIER_LOST = (1<<3);
const int CHANNEL_DOWN = (1<<4);
char flags = 0;

int main() {
		flags |= CHANNEL_DOWN;
		if ((flags & CHANNEL_DOWN) != 0)
			printf("The channel is down\n");
		else
			printf("The channel is up\n");
		flags &= ~CHANNEL_DOWN;
		if ((flags & CHANNEL_DOWN) != 0)
			printf("The channel is down\n");
		else
			printf("The channel is up\n");


}
