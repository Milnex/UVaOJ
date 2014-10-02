#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_set>
using namespace std;


class DisjointSet {
public:
    DisjointSet(const int n) {
        id.resize(n+1);
        sz.resize(n+1, 1);
        iota(id.begin(), id.end(), 0);
    }

    void unite(const int &p, const int &q) {
        const int pi = root(p);
        const int qi = root(q);
        if (pi == qi) return;
        if (sz[pi] < sz[qi]) {
            id[pi] = qi;
            sz[qi] += sz[pi];
        } else {
            id[qi] = pi;
            sz[pi] += sz[qi];
        }
    }

    int count() {
        for (int i = 1; i <= id.size(); ++i)
            id[i] = root(i);
        unordered_set<int> unique(id.begin()+1, id.end());
        return unique.size();
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
};

int main()
{
    for (int n, m, t = 1; scanf("%d%d", &n, &m) == 2 && n; ++t) {
        DisjointSet sets(n);
        for (int i, j; m-- && scanf("%d%d", &i, &j) == 2;)
            sets.unite(i, j);
        printf("Case %d: %d\n", t, sets.count());
    }
    return 0;
}
