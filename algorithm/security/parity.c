#include <stdio.h>

unsigned int hammingWeight(unsigned int data) {
	unsigned int res = data - ((data >> 1) & 0x55);
	res = (res & 0x33) + ((res >> 2) & 0x33);
	return (res  (res >> 4)) & 0x0F;
}

int main() {
	char data = 'a';

	if(hammingWeight(data)%2 == 1)
		data |= 0x80;

// --------- data transfer ---------

	if(hammingWeight(data)%2 == 0)
		printf("Data is valid\n");
	else
		printf("Data is invalid\n");
	return 0;
}
