#include <cstdio>
int main()
{
	int c;
	while ((c = fgetc(stdin)) != EOF)
		printf("%c", c=='\n' ? c : c-7);
	return 0;
}