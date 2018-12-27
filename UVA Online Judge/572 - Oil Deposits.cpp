#include <bits/stdc++.h>
using namespace std;

int M, N;
char grid[110][110];
int dx[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int dy[] = { 1, 0, -1, 0, -1, 1, 1, -1 };

void dfs(int x, int y)
{
    if (grid[x][y] == '@') {
        grid[x][y] = '*';

        for (int a = 0; a < 8; a++) {
            int X = x + dx[a];
            int Y = y + dy[a];

            if (X >= 0 && X < M && Y >= 0 && Y < N)
                dfs(X, Y);
        }
    }
}

int main()
{
    while (scanf("%d %d", &M, &N), (M | N)) {

        for (int a = 0; a < M; a++)
            scanf("%s", grid[a]);

        int ans = 0;

        for (int a = 0; a < M; a++) {
            for (int b = 0; b < N; b++) {
                if (grid[a][b] == '@') {
                    ans++;

                    dfs(a, b);
                }
            }
        }

        printf("%d\n", ans);
    }
}
