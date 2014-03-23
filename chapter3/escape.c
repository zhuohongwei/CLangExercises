#include <stdio.h>

#define MAX_BUFFER_SIZE 5000

void unescape(char *s, char* t);
void escape(char *s, char* t);

main()
{
	char s[] = "The\tquick\nbrown\nfox\tjumped\nover the fence";
	char t[MAX_BUFFER_SIZE];
	unescape(s, t);

	printf("%s\n%s\n", s, t); 

	char u[] = "The\\tquick\\nbrown\\nfox\\tjumped\\nover the fence";
	char v[MAX_BUFFER_SIZE];
	escape(u, v);

	printf("%s\n%s\n", u, v);	
}

void unescape(char *s, char* t)
{
	int c;
	int i;
	i = 0;
	while ((c = *s++) != '\0' && i++ < MAX_BUFFER_SIZE-1) {
		switch(c) {
			case '\n':
				*t++ = '\\';
				if (i++ < MAX_BUFFER_SIZE-1)
					*t++ = 'n';
				break; 
			case '\t': 
				*t++ = '\\';
				if (i++ < MAX_BUFFER_SIZE-1)
					*t++ = 't';
				break;
			default: 
				*t++ = c;
				break;
		}
	}
	*t = '\0';
}

void escape(char *s, char* t)
{
	int c;
	int i;
	i = 0;
	while ((c = *s++) != '\0' && i++ < MAX_BUFFER_SIZE-1) {
		switch(c) {
			case '\\':
				if (*s != '\0') {
					if (*s == 'n') {
						*t++ = '\n';
						*s++;
						continue;
					} else if (*s == 't') {
						*t++ = '\t';
						*s++;
						continue;
					} 
				}
				*t++ = c; 
				break;
			default:
				*t++ = c;
				break;
		}
	}
	*t = '\0';
}

