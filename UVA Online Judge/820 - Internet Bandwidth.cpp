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

int main()
{
    int TC = 0, N;

    while (scanf("%d", &nodes), nodes) {
        memset(res, 0, sizeof(res));

        scanf("%d %d %d", &S, &T, &N);

        S--;
        T--;

        while (N--) {
            int A, B, C;

            scanf("%d %d %d", &A, &B, &C);

            A--;
            B--;

            res[A][B] = res[B][A] = res[A][B] + C;
        }

        printf("Network %d\n", ++TC);
        printf("The bandwidth is %d.\n\n", maxFlow());
    }
}
