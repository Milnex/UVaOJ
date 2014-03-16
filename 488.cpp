#include <cstdio>
int main()
{
	int n, amp, freq;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &amp, &freq);
		while (freq--) {
			for (int i = 1; i < amp; putchar('\n'), i++)
				for (int j = 0; j < i; j++)
					printf("%d", i);
			for (int i = amp; i > 0; putchar('\n'), i--)
				for (int j = 0; j < i; j++)
					printf("%d", i);
			if (freq)
				putchar('\n');
		}
		if (n)
			putchar('\n');
	}
	return 0;
}