#include <cstdio>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class DisjointSet {
public:
    DisjointSet(const unordered_map<string, int> &data) : name(data) {
        id.resize(name.size());
        sz.resize(name.size(), 1);
        iota(id.begin(), id.end(), 0);
    }
    void unite(const string &p, const string &q) {
        const int pi = root(name[p]);
        const int qi = root(name[q]);
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
    unordered_map<string, int> name;
};

int main()
{
    for (int C, R; scanf("%d%d\n", &C, &R) == 2 && C;) {
        unordered_map<string, int> creatures;
        int cid = 0;
        for (string name; C-- && cin >> name; )
            creatures[name] = cid++;
        DisjointSet sets(creatures);
        for (string p, q; R-- && cin >> p >> q; )
            sets.unite(p, q);
        printf("%d\n", sets.largest());
    }
    return 0;
}
