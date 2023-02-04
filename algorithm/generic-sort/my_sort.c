#include <stdio.h>

void generic_swap(void *a, void *b, int size)
{
	char t;

	do {
		t = *(char *)a;
		*(char *)a++ = *(char *)b;
		*(char *)b++ = t;
	} while (--size > 0);
}

int int_cmp (const void* a, const void* b) {
	return *(int *)a - *(int *)b > 0;
}

void bubble_sort(void *a, int n, int size, int (*cmp)(const void*, const void*)) {
	for (int i=0; i<n-1; i++)
		for (int j=0; j<n-1-i; j++)
			if (cmp((char *)a+j*size, (char *)a+(j+1)*size))
				generic_swap((char *)a+j*size, (char *)a+(j+1)*size, size);
}

int main()
{
	int a[] = { 500, 200, 300, 0, 700, 600, 100, 400};
	int i;

	for(i=0; i<(sizeof(a)/4); i++ )
		printf("%4d", a[i] );
	printf("\n");

	bubble_sort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), int_cmp);
	for(i=0; i<(sizeof(a)/4); i++ )
		printf("%4d", a[i] );
	printf("\n");
	return 0;
}
