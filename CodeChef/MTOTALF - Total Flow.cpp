#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_V 1000

int res[MAX_V][MAX_V], S, T, F, nodes = 0;
vector<int> p;
map<string, int> m;

int getIdx(string x)
{
    if (!m.count(x))
        m[x] = nodes++;
    return m[x];
}

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
    int N;

    cin >> N;

    memset(res, 0, sizeof(res));

    while (N--) {
        int C;
        string A, B;

        cin >> A >> B >> C;

        res[getIdx(A)][getIdx(B)] = res[getIdx(B)][getIdx(A)] = res[getIdx(A)][getIdx(B)] + C;
    }

    S = m["A"];
    T = m["Z"];

    printf("%d\n", maxFlow());
}
