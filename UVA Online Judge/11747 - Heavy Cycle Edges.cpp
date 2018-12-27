#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSet;

public:
    UnionFind(int x)
    {
        p.assign(x, 0);
        rank.assign(x, 0);
        setSize.assign(x, 1);

        numSet = x;

        for (int a = 0; a < x; a++)
            p[a] = a;
    }

    int findSet(int x) { return (p[x] == x ? x : findSet(p[x])); }

    bool isSameSet(int x, int y) { return (findSet(x) == findSet(y)); }

    void unionSet(int x, int y)
    {
        int a = findSet(x);
        int b = findSet(y);

        if (!isSameSet(a, b)) {
            numSet--;

            if (rank[a] > rank[b]) {
                p[b] = a;
                setSize[a] += setSize[b];
            } else {
                p[a] = b;
                setSize[b] += setSize[a];

                if (rank[a] == rank[b])
                    rank[b]++;
            }
        }
    }

    int sizeOfSet(int x) { return setSize[findSet(x)]; }

    int numOfSet() { return numSet; }
};

int main()
{
    int N, M;

    while (scanf("%d %d", &N, &M), (N | M)) {
        int U, V, W;
        vector<pair<int, pair<int, int>>> edgeList;

        for (int a = 0; a < M; a++) {
            scanf("%d %d %d", &U, &V, &W);

            edgeList.push_back(make_pair(W, make_pair(U, V)));
        }

        sort(edgeList.begin(), edgeList.end());

        UnionFind UF(N);

        for (int a = 0; a < edgeList.size(); a++) {
            pair<int, int> u = edgeList[a].second;

            if (!UF.isSameSet(u.first, u.second)) {
                UF.unionSet(u.first, u.second);
                edgeList[a].first = 0;
            }
        }

        vector<int> ans;

        for (int a = 0; a < edgeList.size(); a++)
            if (edgeList[a].first != 0)
                ans.push_back(edgeList[a].first);

        for (int a = 0; a < ans.size(); a++)
            if (a)
                printf(" %d", ans[a]);
            else
                printf("%d", ans[a]);

        if (ans.size() == 0)
            printf("forest");

        printf("\n");
    }
}
