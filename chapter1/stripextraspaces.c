#include <stdio.h>

main()
{
	int c;
	int is_blank_seq = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			is_blank_seq = 0;
			putchar(c);
			continue;
		} 
		
		if (!is_blank_seq) {
			is_blank_seq = 1;
			putchar(c);
		}
	}
}