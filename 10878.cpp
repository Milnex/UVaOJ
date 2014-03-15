#include <cstdio>
#include <cstring>
#define LINE_MAX 15

char decode(const char *codes)
{
	return  ((codes[1] == 'o')<<7) | 
			((codes[2] == 'o')<<6) |
			((codes[3] == 'o')<<5) |
			((codes[4] == 'o')<<4) |
			((codes[5] == 'o')<<3) |
			((codes[7] == 'o')<<2) |
			((codes[8] == 'o')<<1) |
			((codes[9] == 'o')<<0)
			;
}

int main()
{
	char tapeline[LINE_MAX];
	fgets(tapeline, sizeof(tapeline), stdin);
	while (fgets(tapeline, sizeof(tapeline), stdin) && strcmp(tapeline, "___________\n"))
		putchar(decode(tapeline));

	return 0;
}