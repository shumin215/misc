#include <stdio.h>
#include <string.h>
#define OUTPUT(x) printf("%d\n", x)

void display(int kmpNext[], int m) {
	for (int i=0; i<m; i++) {
		printf("kmpNext[%d]=%d\n", i, kmpNext[i]);
	}
	printf("\n");
}

void preKmp(char *x, int m, int kmpNext[]) {
	int i, j;

	i = 0;
	j = kmpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = kmpNext[j];
		i++; j++;
		if (x[i] == x[j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;

		if(i > 6) {
			printf("i=%d, j=%d\n", i, j);
			display(kmpNext, m);
		}
	}
}

void KMP(char *x, int m, char *y, int n) {
	int i, j, mpNext[256];

	/* Preprocessing */
	preKmp(x, m, mpNext);

	/* Searching */
	i = j = 0;
	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = mpNext[i];
		i++;
		j++;
		if (i >= m) {
			OUTPUT(j - i);
			i = mpNext[i];
		}
	}
}


int main()
{
	int kmpNext[256] = {0,};
	int i;
	char y[] = "ABCDADDABCDAB";
	char x[] = "ABCDABDZ";

	preKmp(x, strlen(x), kmpNext);

	for(i=0; i<strlen(x); i++)
		printf("%4d", kmpNext[i]);
	printf("\n");

	return 0;
}
