#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#define LINE_WIDTH 60
using namespace std;

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		getchar();
		vector<string> filenames;
		string filename;
		int maxlen = 0;
		for (int i = 0; i < N && getline(cin, filename); i++) {
			if (filename.size() > maxlen)
				maxlen = filename.size();
			filenames.push_back(filename);
		}
		sort(filenames.begin(), filenames.end());

		const int ncols = (LINE_WIDTH - maxlen) / (maxlen + 2) + 1;
		const int nrows = N / ncols + (bool)(N % ncols);

		printf("------------------------------------------------------------\n");

		for (int i = 0; i < nrows; i++)
		{
			for (int j = 0; j < ncols; j++)
			{
				const int idx = j*nrows + i;
				if (idx < N)
					printf("%-*s", maxlen+2, filenames[idx].c_str());
			}
			putchar('\n');
		}
	}
	return 0;
}