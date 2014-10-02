#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class DisjointSet {
public:
    DisjointSet(const int n = 200001) : nid(0) {
        id.resize(n);
        sz.resize(n, 1);
        iota(id.begin(), id.end(), 0);
    }

    int unite(const string &p, const string &q) {
        int pi, qi;
        if (name.find(p) == name.end()) name[p] = pi = nid++;
        else pi = name[p];
        if (name.find(q) == name.end()) name[q] = qi = nid++;
        else qi = name[q];

        const int proot = root(pi);
        const int qroot = root(qi);
        if (proot == qroot) return sz[proot];

        if (sz[proot] < sz[qroot]) {
            id[proot] = qroot;
            sz[qroot] += sz[proot];
            return sz[qroot];
        } else {
            id[qroot] = proot;
            sz[proot] += sz[qroot];
            return sz[proot];
        }
    }
private:
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    vector<int> id;
    vector<int> sz;
    unordered_map<string, int> name;
    int nid;
};

int main()
{
    int n;
    for (scanf("%d", &n); n; n--) {
        int F;
        scanf("%d", &F);
        DisjointSet sets;
        while (F--) {
            string p, q;
            cin >> p >> q;
            printf("%d\n", sets.unite(p, q));
        }
    }
    return 0;
}
