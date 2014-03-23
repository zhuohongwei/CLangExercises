#include <stdio.h>

unsigned rightrot(unsigned x, int n);

main()
{
	//10001
	//11000
	//01100
	//00110
	//00011
	unsigned x = 17;
	int n = 4;
	printf("rightrot %d by %d: %d", x, n, rightrot(x, n));
}

int countbits(unsigned x);
unsigned rightrot(unsigned x, int n)
{
	unsigned bitcount = countbits(x);
	while (n--) {
		x = (x>>1) | ((x&1) << (bitcount-1));
	}
	return x;
}

int countbits(unsigned x)
{ 
	int n;
	for (n = 0; x; x >>= 1, n++)
		;
	return n;
}
