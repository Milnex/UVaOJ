#include <cstdio>
#include <string>
#define PMAX 20
using namespace std;

struct ReverseAndAdd {
    int iter;
    string num;
    ReverseAndAdd(const char *s) : iter(0), num(string(s)) {
        string reversed_num(num.rbegin(), num.rend());
        while (num != reversed_num) {
            num = add(num, reversed_num);
            iter++;
            reversed_num = string(num.rbegin(), num.rend());
        }
    }
    string add(const string &a, const string &b) {
        string sum;
        auto ai = a.rbegin(), bj = b.rbegin();
        int carry = 0;
        while (ai != a.rend() || bj != b.rend() || carry) {
            int d1 = ai!= a.rend() ? *ai-'0' : 0;
            int d2 = bj!= b.rend() ? *bj-'0' : 0;
            int d = d1 + d2 + carry;
            sum += d%10 + '0';
            carry = d/10;

            if (ai != a.rend()) ai++;
            if (bj != b.rend()) bj++;
        }
        return string(sum.rbegin(), sum.rend());
    }
};

int main()
{
    int N;
    char P[PMAX];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", P);
        auto raa = ReverseAndAdd(P);
        printf("%d %s\n", raa.iter, raa.num.c_str());
    }
    return 0;
}
