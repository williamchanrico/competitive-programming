#include <bits/stdc++.h>
using namespace std;

int N;
char grid[110][110];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void dfs(int x, int y)
{
    grid[x][y] = '.';

    for (int a = 0; a < 4; a++) {
        int X = x + dx[a];
        int Y = y + dy[a];

        if (X >= 0 && X < N && Y >= 0 && Y < N && (grid[X][Y] == 'x' || grid[X][Y] == '@'))
            dfs(X, Y);
    }
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int TC = 1; TC <= T; TC++) {
        scanf("%d", &N);

        for (int a = 0; a < N; a++)
            scanf("%s", grid[a]);

        int ans = 0;

        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++)
                if (grid[a][b] == 'x')
                    ans++, dfs(a, b);

        printf("Case %d: %d\n", TC, ans);
    }
}
