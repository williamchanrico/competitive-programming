#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int X, wind[15][1100], memo[15][1100];
int dx[] = { -1, 0, 1 };
int dy[] = { 20, 30, 60 };

int dp(int alt, int dis)
{
    if (alt < 0 || alt > 9 || (dis == X && alt != 0))
        return INF;
    if (dis == X)
        return 0;
    if (memo[alt][dis] != -1)
        return memo[alt][dis];

    memo[alt][dis] = INF;

    for (int a = 0; a < 3; a++)
        memo[alt][dis] = min(memo[alt][dis], dy[a] - wind[alt][dis] + dp(alt + dx[a], dis + 1));

    return memo[alt][dis];
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &X);

        X /= 100;

        for (int a = 9; a >= 0; a--)
            for (int b = 0; b < X; b++)
                scanf("%d", &wind[a][b]);

        memset(memo, -1, sizeof(memo));

        printf("%d\n\n", dp(0, 0));
    }
}