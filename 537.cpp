#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#define C_P (1<<0)
#define C_U (1<<1)
#define C_I (1<<2)
using namespace std;

double readUntil(const char &end)
{
	double value = 0.f;
	string real;
	char c;
	while ((c = cin.peek()) != end && c !='m' && c !='k' && c !='M')
		real += cin.get();

	istringstream iss(real);
	iss >> value;

	c = cin.get();
	if (c == 'm') value *= 1e-3;
	if (c == 'k') value *= 1e3;
	if (c == 'M') value *= 1e6;

	return value;
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) 
	{
		double P = 0.f, U = 0.f, I = 0.f;
		char concepts = 0;
		char c;
		while ((c = cin.get()) != '\n')
		{
			if (cin.peek() != '=') continue;
			cin.ignore();

			if (c == 'P') {
				P = readUntil('W');
				concepts |= C_P;
			}
			else if (c == 'U') {
				U = readUntil('V');
				concepts |= C_U;
			}
			else {
				I = readUntil('A');
				concepts |= C_I;
			}
		}

		printf("Problem #%d\n", i+1);
		if (!(concepts & C_P))
			printf("P=%.2lfW\n\n", U*I);
		else if (!(concepts & C_U))
			printf("U=%.2lfV\n\n", P/I);
		else 
			printf("I=%.2lfA\n\n", P/U);
	}
	return 0;
}