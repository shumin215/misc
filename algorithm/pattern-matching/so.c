#include <stdio.h>
#include <string.h>
#define ASIZE 256
#define OUTPUT(x) printf("%d\n", x)

int preSo(char *x, int m, unsigned int S[]) { 
	unsigned int j, lim; 
	int i; 
	for (i = 0; i < ASIZE; ++i) 
		S[i] = ~0; 
	for (lim = i = 0, j = 1; i < m; ++i, j <<= 1) { 
		S[x[i]] &= ~j; 
		lim |= j; 
	} 
	lim = ~(lim>>1); 
	return(lim); 
} 

void SO(char *x, int m, char *y, int n) { 
	unsigned int lim, state; 
	unsigned int S[ASIZE]; 
	int j; 
//	if (m > WORD) 
//		error("SO: Use pattern size <= word size"); 

	/* Preprocessing */ 
	lim = preSo(x, m, S); 

	/* Searching */ 
	for (state = ~0, j = 0; j < n; ++j) { 
		state = (state<<1) | S[y[j]]; 
		if (state < lim) 
			OUTPUT(j - m + 1); 
	} 
} 

int main() {
	char y[] = "this is hello world";
	char x[] = "hello";

	SO(x, strlen(x), y, strlen(y));

	return 0;
}
