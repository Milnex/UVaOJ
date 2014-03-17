#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cstdio>
using namespace std;

vector<string> tokenize(const string &s)
{
    istringstream iss(s);
    vector<string> tokens;
    string t;

    for (int i = 0; i < 2; i++)
    {
        getline(iss, t, '<');
        tokens.push_back(t);

        getline(iss, t, '>');
        tokens.push_back(t);
    }
    getline(iss, t, '\n');
    tokens.push_back(t);

    return tokens;
}

string schuttelreim(const vector<string> &tokens, const string &s)
{
    string ret = s;
    size_t idx = ret.find("...");
    const string replacement = tokens[3] + tokens[2] + tokens[1] + tokens[4];
    ret.replace(idx, 3, replacement);

    return ret;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) 
    {
        getchar();
        while (n--) 
        {
            string s1, s2;
            getline(cin, s1);
            getline(cin, s2);
            vector<string> tokens = tokenize(s1);
            string c2 = schuttelreim(tokens, s2);
            copy(tokens.begin(), tokens.end(), ostream_iterator<string>(cout, ""));
            cout << endl << c2 << endl;
        }
    }
    return 0;
}
