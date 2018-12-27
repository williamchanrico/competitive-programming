#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_V 1100

long long res[MAX_V][MAX_V];
int S, T, F, nodes = 0;
vector<int> p;

void augment(int u, long long minEdge)
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
    int N, M;

    while (scanf("%d %d", &N, &M) != EOF) {
        memset(res, 0, sizeof(res));

        S = 0;
        T = M - 1;
        nodes = M;

        while (N--) {
            int A, B, C;

            scanf("%d %d %d", &A, &B, &C);

            A--;
            B--;

            res[A][B] += C;
        }

        printf("%d\n", maxFlow());
    }
}
