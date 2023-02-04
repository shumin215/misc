#include <stdio.h>

void swap (void *a, void *b, int size) {
	char t;
	int i;
	char *pa = (char *)a;
	char *pb = (char *)b;

	for(i=0; i<size; i++) {
		t = pa[i];
		pa[i] = pb[i];
		pb[i] = t;
	}
}

int main() {
	int a=3, b=4;
	double ad = 3., bd = 4.;

	swap(&a, &b, sizeof(a));
	swap(&ad, &bd, sizeof(ad));

	printf("a  = %d, b = %d\n", a, b);
	printf("ad = %lf, bb = %lf\n", ad, bd);
	return 0;
}
