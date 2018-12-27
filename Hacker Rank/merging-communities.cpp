#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    int numSet;
    vector<int> p, rank, setSize;

public:
    UnionFind() {}

    UnionFind(int x)
    {
        numSet = x;

        p.assign(x, 0);
        rank.assign(x, 0);
        setSize.assign(x, 1);

        for (int a = 0; a < x; a++) {
            p[a] = a;
        }
    }

    int findSet(int x) { return (x == p[x] ? x : findSet(p[x])); }

    bool isSameSet(int x, int y) { return (findSet(p[x]) == findSet(p[y])); }

    int sizeOfSet(int x) { return setSize[findSet(x)]; }

    int numOfSet() { return numSet; }

    void unionSet(int x, int y)
    {
        if (isSameSet(x, y))
            return;

        int A = findSet(x);
        int B = findSet(y);

        if (rank[A] < rank[B]) {
            p[A] = B;
            setSize[B] += setSize[A];
        } else {
            p[B] = A;
            setSize[A] += setSize[B];

            if (rank[A] == rank[B])
                ++rank[A];
        }

        --numSet;
    }
};

void fflush()
{
    char c;
    while ((c = getchar()) != EOF && c != '\n')
        ;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int N, Q;
    scanf("%d %d", &N, &Q);

    UnionFind uf(N);

    while (Q--) {
        char query;
        int n1, n2;

        fflush();
        scanf("%c", &query);

        switch (query) {
        case 'Q':
            scanf("%d", &n1);
            printf("%d\n", uf.sizeOfSet(n1 - 1));
            break;
        case 'M':
            scanf("%d %d", &n1, &n2);
            uf.unionSet(n1 - 1, n2 - 1);
            break;
        }
    }
}