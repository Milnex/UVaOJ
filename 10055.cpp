#include <cstdio>
int main()
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b) == 2)
		printf("%lld\n", a<b ? b-a : a-b);
	return 0;
}