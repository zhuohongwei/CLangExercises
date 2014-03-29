#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);
int len(char s[]);

main()
{
	char s[9];
	int i;

	for (i = 0; i < 256; i++) {
		itoa(i, s);
		printf("%d = %s\n", i, s);
	} 
}

/*converts an integer into its binary string representation*/
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n%2 + '0';
	} while ((n /= 2) > 0);

	if (sign < 0)
		s[i++] = '1'; 
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j;
	i = 0;
	j = len(s) - 1;
	while (i < j) {
		s[i] ^= s[j];
		s[j] ^= s[i];
		s[i] ^= s[j];
		i++; 
		j--;
	}
}

int len(char s[])
{
	int n = 0;
	while (*s++ != '\0') {
		n++;
	}
	return n;
}
