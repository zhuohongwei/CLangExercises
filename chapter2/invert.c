#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	// p = 4
	// n = 2
	// x = 101010110
	// result = 101001110
	printf("inverting %d produces %d\n", 342, invert(342, 4, 2));
}

/*
Invert n bits in x starting from position p
*/
unsigned invert(unsigned x, int p, int n)
{
	return ((x >> p+1) << p+1) //turn off the lower p+1 bits
	| (x & ~(~0 << (p+1-n))) //turn on the tail bits, leaving only the n bits in-between off
	| ((~(x & (~(~0 << n) << (p+1-n)))) & (~(~0 << n) << (p+1-n))); //extract the relevant n bits, reverse it and combine
}