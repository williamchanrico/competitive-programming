#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

char grid[110][110];
int N, M, K, startX, startY, memo[110][110][5100];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int dp(int x, int y, int z)
{
    if (grid[x][y] == '#')
        return 0;
    if (x < 0 || x >= N || y < 0 || y >= M || z < 0)
        return 0;
    if (z == 0 && x == startX && y == startY)
        return 1;
    if (memo[x][y][z] != -1)
        return memo[x][y][z];

    memo[x][y][z] = 0;

    for (int a = 0; a < 4; a++) {
        int X = x + dx[a];
        int Y = y + dy[a];

        memo[x][y][z] = (memo[x][y][z] + dp(X, Y, z - 1)) % MOD;
    }

    return memo[x][y][z] % MOD;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    startX = startY = -1;

    for (int a = 0; a < N; a++) {
        scanf("%s", grid[a]);

        if (startX == -1) {
            for (int b = 0; b < M; b++) {
                if (grid[a][b] == 'R') {
                    startX = a;
                    startY = b;
                }
            }
        }
    }

    memset(memo, -1, sizeof(memo));

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
            int ans = dp(a, b, K);

            printf("%d ", ans == -1 ? 0 : ans);
        }
        printf("\n");
    }
}
