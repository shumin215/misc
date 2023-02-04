#include <stdio.h>
#define BITS_PER_LONG 32
#define BITOP_WORD(nr)		((nr) / BITS_PER_LONG)
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
	(byte & 0x80 ? '1' : '0'), \
	(byte & 0x40 ? '1' : '0'), \
	(byte & 0x20 ? '1' : '0'), \
	(byte & 0x10 ? '1' : '0'), \
	(byte & 0x08 ? '1' : '0'), \
	(byte & 0x04 ? '1' : '0'), \
	(byte & 0x02 ? '1' : '0'), \
	(byte & 0x01 ? '1' : '0') 
unsigned long __ffs(unsigned long word)
{
	int num = 0;

#if BITS_PER_LONG == 64
	if ((word & 0xffffffff) == 0) {
		num += 32;
		word >>= 32;
	}
#endif
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}
unsigned long find_next_bit(const unsigned long *addr, unsigned long size,
		unsigned long offset)
{
	const unsigned long *p = addr + BITOP_WORD(offset);
	unsigned long result = offset & ~(BITS_PER_LONG-1);
	printf("result: %lu\n", result);

	unsigned long tmp;

	if (offset >= size)
		return size;
	printf("size: %lu\n", size);
	size -= result;
	printf("size: %lu\n", size);
	offset %= BITS_PER_LONG;
	if (offset) {
		tmp = *(p++);
		tmp &= (~0UL << offset);
//		printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(tmp));
		if (size < BITS_PER_LONG)
			goto found_first;
		if (tmp)
			goto found_middle;
		size -= BITS_PER_LONG;
		result += BITS_PER_LONG;
	}
	while (size & ~(BITS_PER_LONG-1)) {
		if ((tmp = *(p++)))
			goto found_middle;
		result += BITS_PER_LONG;
		size -= BITS_PER_LONG;
	}
	if (!size)
		return result;
	tmp = *p;

found_first:
	tmp &= (~0UL >> (BITS_PER_LONG - size));
	if (tmp == 0UL)		/* Are any bits set? */
		return result + size;	/* Nope. */
found_middle:
	return result + __ffs(tmp);
}
int main()
{
	unsigned long bitmap[3] = {0,};
	unsigned long index;
	// Host process
	bitmap[10/64] |= 1UL << (10%64);
	bitmap[50/64] |= 1UL << (50%64);
	bitmap[70/64] |= 1UL << (70%64);
	// Guest process
	bitmap[105/64] |= 1UL << (105%64);
	bitmap[110/64] |= 1UL << (110%64);
	bitmap[115/64] |= 1UL << (115%64);
	// Reserved
	bitmap[151/64] |= 1UL << (151%64);
//	int pattern = 0x8000001f;
	index = find_next_bit(bitmap, 150, 100);
	if( index )
		printf("가장 우선순위가 높은 프로세스는 %lu입니다.\n", index );
	return 0;
}
