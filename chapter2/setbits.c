#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main() 
{
	// p = 4
	// n = 2
	// x = 101010110
	// y = 000000011
	// result = 101011110
	printf("%d\n", setbits(342, 4, 2, 3));
}

/*
Sets n bits in x starting from position p by replacing with n bits from y
*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (((x >> (p+1)) << (p+1)) | (x & ~(~0 << p+1-n))) | ((y & ~(~0 << n)) << (p+1-n)); 	 
}

