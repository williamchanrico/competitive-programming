#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, pair<int, int>> pip;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        int N, M, cost[1100][1100];

        scanf("%d %d", &N, &M);

        for (int a = 0; a < N; a++)
            for (int b = 0; b < M; b++)
                scanf("%d", &cost[a][b]);

        vector<int> dist(N * M, INF);
        priority_queue<pip, vector<pip>, greater<pip>> pq;

        dist[0] = cost[0][0];
        pq.push(make_pair(0, make_pair(0, 0)));

        while (!pq.empty()) {
            pip u = pq.top();

            pq.pop();

            int d = u.first;
            pair<int, int> v = u.second;

            if (d > dist[v.first * M + v.second])
                continue;

            for (int a = 0; a < 4; a++) {
                int X = v.first + dx[a];
                int Y = v.second + dy[a];

                if (X >= 0 && X < N && Y >= 0 && Y < M) {
                    if (dist[v.first * M + v.second] + cost[X][Y] < dist[X * M + Y]) {
                        dist[X * M + Y] = dist[v.first * M + v.second] + cost[X][Y];

                        pq.push(make_pair(dist[X * M + Y], make_pair(X, Y)));
                    }
                }
            }
        }

        printf("%d\n", dist[(N - 1) * M + (M - 1)]);
    }
}
