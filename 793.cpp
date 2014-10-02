#include <cstdio>
#include <vector>
using namespace std;

class DisjointSet {
public:
    DisjointSet(const int n) {
        id.resize(n+1);
        sz.resize(n+1, 1);
        for (int i = 1; i <= n; ++i)
            id[i] = i;
    }
    void unite(const int p, const int q) {
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
    int find(const int i) {
        return root(i);
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
    int cases = 0;
    for (scanf("%d", &cases); cases > 0; --cases) {
        int n = 0;
        scanf("%d", &n);
        fgetc(stdin);
        DisjointSet sets(n);

        char type;
        int p, q, yes = 0, no = 0;
        while ((type = fgetc(stdin)) != EOF && type != '\n' && scanf("%d%d", &p, &q) == 2) {
            fgetc(stdin);
            if (type == 'c') {
                sets.unite(p, q);
                continue;
            }
            if (sets.find(p) == sets.find(q))
                ++yes;
            else
                ++no;
        }
        printf("%d,%d\n", yes, no);
        if (cases > 1) putchar('\n');
    }

    return 0;
}
