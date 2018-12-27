#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        int N, M;

        scanf("%d %d", &N, &M);

        int X, Y, Z;
        vector<vector<pair<int, int>>> adjList(N);

        for (int a = 0; a < M; a++) {
            scanf("%d %d %d", &X, &Y, &Z);

            adjList[X].push_back(make_pair(Y, Z));
        }

        vector<int> dist(N, INF);

        dist[0] = 0;

        for (int a = 0; a < (N - 1); a++) {
            for (int b = 0; b < N; b++) {
                for (int c = 0; c < adjList[b].size(); c++) {
                    pair<int, int> v = adjList[b][c];

                    dist[v.first] = min(dist[v.first], dist[b] + v.second);
                }
            }
        }

        bool hasCycle = false;

        for (int a = 0; a < N; a++)
            for (int b = 0; b < adjList[a].size(); b++)
                if (dist[a] + adjList[a][b].second < dist[adjList[a][b].first])
                    hasCycle = true;

        printf("%s\n", (hasCycle ? "possible" : "not possible"));
    }
}
