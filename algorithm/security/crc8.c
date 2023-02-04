#include <stdio.h>
typedef unsigned char u8;
#define CRC8_TABLE_SIZE         256
void crc8_populate_msb(u8 *table, u8 polynomial)
{
	int i, j;
	const u8 msbit = 0x80;
	u8 t = msbit;

	table[0] = 0;

	for (i = 1; i < CRC8_TABLE_SIZE; i *= 2) {
		t = (t << 1) ^ (t & msbit ? polynomial : 0);
		for (j = 0; j < i; j++)
			table[i+j] = table[j] ^ t;
	}
}
u8 crc8( u8 *table, u8 *pdata, size_t nbytes, u8 crc)
{
	while (nbytes-- > 0)
		crc = table[(crc ^ *pdata++) & 0xff];

	return crc;
}

u8 table[CRC8_TABLE_SIZE];

void display( u8 *table )
{
	int i;
	for( i=0; i<256; i++ )
	{
		printf("%02x ", table[i] );
		if( (i+1)%16 == 0 )
			printf("\n");
	}
}

int main()
{
	u8 data[3] = {0x14, 0x52, 0 };
//	crc8(0x14) = 0xAC (1010_1100)
//	             0x52 (0101_0010) ^
//	             0xFE (1111_1110)
	u8 crc = 0x0;
	crc8_populate_msb(table, 0xd5);
	display( table );
	crc = crc8( table, data, 2, 0 );
	printf("crc=%#x\n", crc );
	data[2] = crc;
//	data[0]++;
//	data[1]--;
	//============================================
	crc = crc8( table, data, 3, 0 );
	if( crc == 0 )
		printf("Data is valid\n");
	else
		printf("Data is invalid\n");
	return 0;
}
