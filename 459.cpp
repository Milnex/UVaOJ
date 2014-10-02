#include <vector>
#include <unordered_set>
#include <cstdio>
using namespace std;

class DisjointSet {
public:
    DisjointSet(const int n = MAX_SIZE) {
        id.resize(n);
        sz.resize(n, 1);
        reset();
    }
    void unite (int p, int q) {
        const int i = root(p);
        const int j = root(q);
        if (i == j) return;

        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
    int count(int n) {
        unordered_set<int> roots;
        for (int i = 0; i < n; ++i)
            roots.insert(root(i));
        return roots.size();
    }
    void reset() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            id[i] = i;
            sz[i] = 1;
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
    const static int MAX_SIZE = 26;
    vector<int> id;
    vector<int> sz;
};

int main()
{
    DisjointSet sets;
    int cases = 0;
    for (scanf("%d\n", &cases); cases > 0; --cases) {
        char end = '\0', edge[4];
        scanf("%c", &end);
        fgetc(stdin);
        while (fgets(edge, 4, stdin) && edge[0] != '\n')
            sets.unite(edge[0]-'A', edge[1]-'A');
        printf("%d\n", sets.count(end-'A'+1));
        if (cases > 1) {
            putchar('\n');
            sets.reset();
        }
    }
    return 0;
}
