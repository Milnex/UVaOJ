#include <cstdio>
#include <cctype>
int main()
{
	int c, n = 0;
	bool word = true;
	while ((c = fgetc(stdin)) != EOF){
		if (c == '\n') {
			printf("%d\n", n);
			n = 0;
			word = true;
		}
		else if (isalpha(c) && word) {
			n++;
			word = false;
		}
		else if (!isalpha(c))
			word = true;
	}
	return 0;
}