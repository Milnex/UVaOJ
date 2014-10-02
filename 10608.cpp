#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    DisjointSet(const int &n) {
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
    int largest() const {
        return *max_element(sz.begin(), sz.end());
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
    int n;
    for (scanf("%d", &n); n; n--) {
        int N, M;
        scanf("%d%d", &N, &M);
        DisjointSet sets(N);
        while (M--) {
            int A, B;
            scanf("%d%d", &A, &B);
            sets.unite(A, B);
        }
        printf("%d\n", sets.largest());
    }
    return 0;
}
