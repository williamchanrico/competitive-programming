#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        int N, E, M, timer;

        scanf("%d %d %d %d", &N, &E, &timer, &M);

        int A, B, C;
        vector<vector<pair<int, int>>> adjList(N);

        for (int a = 0; a < M; a++) {
            scanf("%d %d %d", &A, &B, &C);

            adjList[B - 1].push_back(make_pair(A - 1, C));
        }

        vector<int> dist(N, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[E - 1] = 0;
        pq.push(make_pair(0, E - 1));

        while (!pq.empty()) {
            pii front = pq.top();

            pq.pop();

            int d = front.first;
            int u = front.second;

            if (d > dist[u])
                continue;

            for (int a = 0; a < adjList[u].size(); a++) {
                pair<int, int> v = adjList[u][a];

                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;

                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }

        int ans = 0;

        for (int a = 0; a < N; a++)
            if (dist[a] <= timer)
                ans++;

        printf("%d\n", ans);

        if (T)
            printf("\n");
    }
}
