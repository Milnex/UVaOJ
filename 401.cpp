#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const char table[] = "1SE.Z..8........A...3..HIL.JM.O...2TUVWXY5";

bool isMirrored(const string & s)
{
	string mirrored;
	for (int i = s.length()-1; i >= 0; i--)
		mirrored += table[s[i]-'1'];
	return s == mirrored;
}

bool isPalindrome(const string & s)
{
	for (int i = 0, j = s.length()-1; i < j; i++, j--)
		if (s[i] != s[j])
			return false;
	return true;
}

int main()
{
	string input;
	while (cin >> input) {
		bool is_mirrored = isMirrored(input);
		bool is_palindrome = isPalindrome(input);

		printf("%s -- ", input.c_str());
		if (is_mirrored && is_palindrome)
			printf("is a mirrored palindrome.");
		else if (is_mirrored && !is_palindrome)
			printf("is a mirrored string.");
		else if (!is_mirrored && is_palindrome)
			printf("is a regular palindrome.");
		else 
			printf("is not a palindrome.");
		printf("\n\n");
	}
	return 0;
}