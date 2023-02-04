#include <stdio.h>

int bit_count(int bit) {
	int count = 0;
	while (bit > 0) {
		count += bit & 0x1;
		bit = bit >> 1;
	}

	return count;
}

int main() {
	int bit_map = 0x12345678;
	int count = bit_count(bit_map);;
	printf("0x%x = %d\n", bit_map, count);
	return 0;
}
