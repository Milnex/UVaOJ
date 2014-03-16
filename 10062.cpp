#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define INPUT_MAX 1010
using namespace std;
int main()
{
	char line[INPUT_MAX];
	for (bool init = 1; fgets(line, INPUT_MAX, stdin); init = 0) {
		unsigned ascii[256] = {0};

		for (int i = 0; line[i]; i++)
			ascii[line[i]]++;

		vector<pair<unsigned, unsigned>> pairs;
		for (int i = 32; i < 128; i++)
			if (ascii[i])
				pairs.push_back(make_pair(ascii[i], i));
		sort(pairs.begin(), pairs.end(), 
		     [](const pair<unsigned, unsigned> &a, const pair<unsigned, unsigned> &b) {
		     	return a.first == b.first ? a.second > b.second : a.first < b.first;
		     });

		if (!init) putchar('\n');
		for (auto &p: pairs)
			printf("%u %u\n", p.second, p.first);
	}

	return 0;
}