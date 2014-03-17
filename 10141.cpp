#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define N 100
using namespace std;

struct RFP {
    double price;
    int req;
    string name;
    RFP(const char *_name, double _p, int _r) : 
        name(_name), price(_p), req(_r) {}
};

int main()
{
    int n, p;
    for (int c = 1; scanf("%d%d", &n, &p) == 2 && (n || p); c++) {
        fgetc(stdin);
        char line[N];
        vector<RFP> rfps;
        for (int i = 0; i < n; i++)
            fgets(line, N, stdin);
        for (int i = 0; i < p; i++) {
            double d;
            int r;
            fgets(line, N, stdin);
            scanf("%lf%d", &d, &r);
            rfps.push_back(RFP(line, d, r));
            for (fgetc(stdin); r--; fgets(line, N, stdin));
        }
        stable_sort(rfps.begin(), rfps.end(), [](const RFP &a, const RFP &b){
            return a.req == b.req ? a.price < b.price : a.req > b.req;
        });
        printf("%sRFP #%d\n%s", (c>1 ? "\n" : ""), c, (p ? rfps[0].name.c_str() : ""));
    }
    return 0;
}