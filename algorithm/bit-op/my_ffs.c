#include <stdio.h>

int my_ffs(int bitmap) {
	int i;
	for(i=0; i<32; i++)
		if(bitmap & (i<<i))
			break;
	return i;
}

int main() {
	int bitmap = 0x01000000;
	printf("%d\n", my_ffs(bitmap));
	return 0;
}
