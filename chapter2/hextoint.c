#include <stdio.h>

int hextoint(char *s);
int basetopower(int b, int p);

main()
{
	printf("%s is equal to %d\n", "0xfafafa", hextoint("0xfafafa"));
}

int hextoint(char *s)
{
	int n, d, power;
	char *p;

	if (*s == '0') s++;
	if (*s == 'x' || *s == 'X') s++;
	
	p = s; 
	for (; *p != '\0'; p++);

	p -= 1;
	power = 0; 
	while(p >= s) {
		putchar(*p);
		if (*p >= '0' && *p <= '9') {
			d = *p-- - '0';	
		} else if (*p >= 'a' && *p <= 'f') {
			d = 10 + (*p-- - 'a'); 
		} else if (*p >= 'A' && *p <= 'F') {
			d = 10 + (*p-- - 'A');
		} else {
			printf("Encountered invalid characters in hexadecimal string\n");
			return 0;
		}
		n += (d * basetopower(16, power++));
	}

	return n;
}

int basetopower(int b, int p)
{
	if (p == 0) return 1;
	return b * basetopower(b, --p);
}