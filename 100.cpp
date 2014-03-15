#include <cstdio>
#include <algorithm>

int cycle_length(int n) {
	int len = 1;
	while (n != 1) {
		if (n & 1) {
			n = (3*n + 1) / 2;
			len += 2;
		}
		else {
			n = n/2;
			len ++;
		}
	}
	return len;
}

int main()
{
	int i, j;
	while (scanf("%d%d", &i, &j) == 2) {
		printf("%d %d ", i, j);
		if (i > j)
			std::swap(i, j);

		int max_length = cycle_length(i);
		while (++i <= j) {
			int next_length = cycle_length(i);
			if (next_length > max_length)
				max_length = next_length;
		}
		printf("%d\n", max_length);
	}

	return 0;
}