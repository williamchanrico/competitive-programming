#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_V 1100

int res[MAX_V][MAX_V], S, T, F, nodes = 0;
vector<int> p;

void augment(int u, int minEdge)
{
    if (u == S) {
        F = minEdge;

        return;

    } else if (p[u] != -1) {
        augment(p[u], min(minEdge, res[p[u]][u]));

        res[p[u]][u] -= F;
        res[u][p[u]] += F;
    }
}

int maxFlow()
{
    int maxF = 0;

    while (true) {
        vector<int> dist(nodes, INF);
        queue<int> q;

        dist[S] = 0;
        q.push(S);
        p.assign(nodes, -1);

        while (!q.empty()) {
            int u = q.front();

            q.pop();

            if (u == T)
                break;

            for (int a = 0; a < nodes; a++) {
                if (res[u][a] > 0 && dist[a] == INF) {
                    dist[a] = dist[u] + 1;
                    q.push(a);
                    p[a] = u;
                }
            }
        }

        F = 0;

        augment(T, INF);

        if (F == 0)
            break;

        maxF += F;
    }

    return maxF;
}

/*
    Regulator nodes index representation
    Transform every Nth regulator with capacity C to a node with
    index (2N - 1) and is connected to a new node indexed (2N)
    with link capacity C.

    example
        4th regulator with capacity 40

        node's index = (2 * 4 - 1) = 7
        new node's index = (2 * 4) = 8
        new link from node 7 to 8 = 40

        if there's a link from 4th regulator to 5th, it becomes a link
        from node 8, not node 7, to node 9 (2 * 5 - 1).   
*/

int nodeIdx(int x) { return 2 * x - 1; }

int main()
{
    int N;

    while (scanf("%d", &nodes) != EOF) {
        memset(res, 0, sizeof(res));

        for (int a = 1; a <= nodes; a++)
            scanf("%d", &res[nodeIdx(a)][nodeIdx(a) + 1]);

        S = 0;
        T = (2 * nodes) + 1;
        nodes = (2 * nodes) + 2;

        scanf("%d", &N);

        while (N--) {
            int A, B, C;

            scanf("%d %d %d", &A, &B, &C);

            res[nodeIdx(A) + 1][nodeIdx(B)] += C;
        }

        int entryCount, exitCount, inp;

        scanf("%d %d", &entryCount, &exitCount);

        while (entryCount--) {
            scanf("%d", &inp);

            res[S][nodeIdx(inp)] = INF;
        }

        while (exitCount--) {
            scanf("%d", &inp);

            res[nodeIdx(inp) + 1][T] = INF;
        }

        printf("%d\n", maxFlow());
    }
}
