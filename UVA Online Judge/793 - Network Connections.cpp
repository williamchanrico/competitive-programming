#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    int numSet;
    vector<int> p, rank, setSize;

public:
    UnionFind(int x)
    {
        numSet = x;
        p.assign(x + 1, 0);
        rank.assign(x + 1, 0);
        setSize.assign(x + 1, 1);

        for (int a = 0; a <= x; a++)
            p[a] = a;
    }

    int findSet(int x) { return (p[x] == x ? x : findSet(p[x])); }

    bool isSameSet(int x, int y) { return (findSet(p[x]) == findSet(p[y])); }

    void unionSet(int x, int y)
    {
        if (!isSameSet(x, y)) {
            int a = findSet(x);
            int b = findSet(y);

            if (rank[a] > rank[b]) {
                p[b] = a;
                setSize[a] += setSize[b];
            } else {
                p[a] = b;
                setSize[b] += setSize[a];
                if (rank[a] == rank[b])
                    rank[b]++;
            }

            numSet--;
        }
    }

    int sizeOfSet(int x) { return setSize[findSet(x)]; }
};

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        char cmd;
        int success = 0, failed = 0, N, x, y;

        scanf("%d ", &N);

        UnionFind UF(N);

        while (true) {
            string s;

            if (getline(cin, s), s == "")
                break;

            sscanf(s.c_str(), "%c %d %d", &cmd, &x, &y);

            if (cmd == 'c')
                UF.unionSet(x, y);
            else if (UF.isSameSet(x, y))
                success++;
            else
                failed++;
        }

        printf("%d,%d\n", success, failed);

        if (T)
            printf("\n");
    }
}
