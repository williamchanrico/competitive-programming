#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int E, N, inp;

    scanf("%d", &E);

    vector<vector<int>> adjList(E);

    for (int a = 0; a < E; a++) {

        scanf("%d", &N);

        for (int b = 0; b < N; b++) {
            scanf("%d", &inp);

            adjList[a].push_back(inp);
        }
    }

    scanf("%d", &N);

    while (N--) {
        int M = 0, D = 1, S;
        queue<int> q;
        vector<int> dist(E, INF);

        scanf("%d", &S);

        q.push(S);

        dist[S] = 0;

        while (!q.empty()) {
            int u = q.front();

            q.pop();

            for (int a = 0; a < adjList[u].size(); a++) {

                if (dist[adjList[u][a]] == INF) {
                    q.push(adjList[u][a]);

                    dist[adjList[u][a]] = dist[u] + 1;
                }
            }

            if (q.size() > M && dist[q.front()] == (dist[u] + 1)) {
                M = q.size();
                D = dist[u] + 1;
            }
        }

        if (M == 0)
            printf("0\n");
        else
            printf("%d %d\n", M, D);
    }
}
