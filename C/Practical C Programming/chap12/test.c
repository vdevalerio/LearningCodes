#include <stdio.h>
#include <string.h>

#define TEST3

#ifdef TEST1
int main() {
	struct bin {
		char part_name[30];
		float quantity;
		float part_cost;
	} printer_cable_bin;
	printer_cable_bin.part_cost = 12.95;
	printf("The price of the cables is %.2f.\n", printer_cable_bin.part_cost);
	return(0);
}
#endif /* TEST1 */

#ifdef TEST2

#define DATA_MAX 1024
typedef struct open_msg {
	char name[30];
};
struct read_msg {
	int length;
};
struct write_msg {
	int length;
	char data[DATA_MAX];
};
struct close_msg {
};

const int OPEN_CODE = 0;
const int READ_CODE = 1;
const int WRITE_CODE = 2;
const int CLOSE_CODE = 3;

struct msg {
	int msg;
	union {
		struct open_msg open_data;
		struct read_msg read_data;
		struct write_msg write_data;
		struct close_msg close_data;
	} msg_data;
};

int main() {
	struct msg message = {
		0,
		"Message's Name"
	};
	printf("Message's type: %d.\nData: %s.\n", message.msg, message.msg_data.open_data.name);
	return(0);
}

#endif /* TEST2 */

#ifdef TEST3
int main() {
	typedef struct complex_numbers {
		double real;
		double imag;
	} complex;
	complex number1;
	number1.real = 3.5;
	number1.imag = 1.2;
	complex number2 = {3.5, 1.2};
	printf("Number 1: %.1f+%.1fi\n", number1.real, number1.imag);
	return(0);
}
#endif
