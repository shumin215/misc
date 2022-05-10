#include <iostream>
#include <math.h>

#define LONG_BIT_CNT 64
#define INT_BIT_CNT 32

void printIntAsBinary(int num)
{
	int binary[INT_BIT_CNT] = {0,};
	unsigned long decimal, remainder, idx = 0;

	unsigned int *input = (unsigned int *)&num;

	for (int i=0; i<INT_BIT_CNT; i++) {
		binary[i] = ((*input) & (0x1L << i)) >> i;
	}
	for (int i=0; i<INT_BIT_CNT; i++)
		printf("%d", binary[INT_BIT_CNT-1-i]);
	printf("\n");
}

void printLongAsBinary(long num)
{
	int binary[LONG_BIT_CNT] = {0,};
	unsigned long decimal, remainder, idx = 0;

	unsigned long *input = (unsigned long *)&num;

	for (int i=0; i<LONG_BIT_CNT; i++) {
		binary[i] = ((*input) & (0x1L << i)) >> i;
	}
	for (int i=0; i<LONG_BIT_CNT; i++)
		printf("%d", binary[LONG_BIT_CNT-1-i]);
	printf("\n");
}

void printFloatAsBinary(float num)
{
	int binary[INT_BIT_CNT] = {0,};
	unsigned long decimal, remainder, idx = 0;

	unsigned int *input = (unsigned int *)&num;

	for (int i=0; i<INT_BIT_CNT; i++) {
		binary[i] = ((*input) & (0x1L << i)) >> i;
	}
	for (int i=0; i<INT_BIT_CNT; i++)
		printf("%d", binary[INT_BIT_CNT-1-i]);
	printf("\n");
}

void printDoubleAsBinary(double num)
{
	int binary[LONG_BIT_CNT] = {0,};
	unsigned long decimal, remainder, idx = 0;

	unsigned long *input = (unsigned long *)&num;

	for (int i=0; i<LONG_BIT_CNT; i++) {
		binary[i] = ((*input) & (0x1L << i)) >> i;
	}
	for (int i=0; i<LONG_BIT_CNT; i++)
		printf("%d", binary[LONG_BIT_CNT-1-i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
  // 1. int
  int i;
  std::cin >> i;

  // 2. long
  long l;
  std::cin >> l;

  // 3. float
  float f;
  std::cin >> f;

  // 4. double
  double d;
  std::cin >> d;

  printIntAsBinary(i);
  printLongAsBinary(l);
  printFloatAsBinary(f);
  printDoubleAsBinary(d);

  return 0;
}
