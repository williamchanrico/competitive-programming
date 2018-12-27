#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int N, x[15], y[15], dist[15][15], memo[25][1 << 15];

int dp(int pos, int bitmask)
{
    if (bitmask == (1 << N) - 1)
        return dist[pos][0];
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    memo[pos][bitmask] = INF;

    for (int a = 1; a < N; a++)
        if (pos != a && !(bitmask & (1 << a)))
            memo[pos][bitmask] = min(memo[pos][bitmask], dist[pos][a] + dp(a, (bitmask | (1 << a))));

    return memo[pos][bitmask];
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        scanf("%*d %*d %d %d %d", &x[0], &y[0], &N);

        N++;

        for (int a = 1; a < N; a++)
            scanf("%d %d", &x[a], &y[a]);

        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++)
                dist[a][b] = abs(x[b] - x[a]) + abs(y[b] - y[a]);

        memset(memo, -1, sizeof(memo));

        printf("The shortest path has length %d\n", dp(0, 1));
    }
}