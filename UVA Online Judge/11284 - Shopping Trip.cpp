#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define EPS 1e-9

int N, M, P, store[15];
double dist[60][60], cost[15][15], save[15], memo[13][1 << 13];

double dp(int pos, int bitmask)
{
    if (bitmask == ((1 << P) - 1))
        return -cost[pos][0];
    if (memo[pos][bitmask] != -1.0)
        return memo[pos][bitmask];

    memo[pos][bitmask] = -INF;

    for (int a = 0; a < P; a++)
        if (pos != a && !(bitmask & (1 << a)))
            memo[pos][bitmask] = max(memo[pos][bitmask], max(save[a] - cost[pos][a] + dp(a, bitmask | (1 << a)), save[a] - cost[pos][a] - cost[a][0]));

    return memo[pos][bitmask];
}

void reset()
{
    for (int a = 0; a < 13; a++)
        for (int b = 0; b < (1 << 13); b++)
            memo[a][b] = -1.0;

    for (int a = 0; a <= 50; a++)
        for (int b = 0; b <= 50; b++)
            dist[a][b] = INF;
}

void floyd()
{
    for (int a = 0; a < N; a++)
        dist[a][a] = 0;

    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++)
            for (int c = 0; c < N; c++)
                dist[b][c] = min(dist[b][c], dist[b][a] + dist[a][c]);
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        reset();

        scanf("%d %d", &N, &M);

        N++;

        for (int a = 0; a < M; a++) {
            int x, y;
            double cost;

            scanf("%d %d %lf", &x, &y, &cost);

            dist[x][y] = dist[y][x] = min(dist[x][y], cost);
        }

        floyd();

        scanf("%d", &P);

        P++;

        for (int a = 1; a < P; a++) {
            scanf("%d %lf", &store[a], &save[a]);

            cost[0][a] = cost[a][0] = dist[0][store[a]];
        }

        for (int a = 1; a < P; a++)
            for (int b = 1; b < P; b++)
                cost[a][b] = dist[store[a]][store[b]];

        double ans = dp(0, 1);

        if (ans < 0 || fabs(ans - 0) < EPS)
            printf("Don't leave the house\n");
        else
            printf("Daniel can save $%.2lf\n", ans);
    }
}