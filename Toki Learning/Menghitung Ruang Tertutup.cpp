#include <bits/stdc++.h>
using namespace std;

int N, M;
char inp[255][255], data[1000][1000];
char titik[3][3] = { '.', '.', '.',
    '.', '.', '.',
    '.', '.', '.' };
char slash[3][3] = { '.', '.', '/',
    '.', '/', '.',
    '/', '.', '.' };
char backs[3][3] = { '\\', '.', '.',
    '.', '\\', '.',
    '.', '.', '\\' };

void dfs(int x, int y)
{
    if (data[x][y] == '.' && x < N * 3 && y < M * 3 && x > -1 && y > -1) {
        data[x][y] = '#';
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
    }
}

int main()
{
    cin >> N >> M;
    for (int a = 0; a < N; a++)
        for (int b = 0; b < M; b++)
            cin >> inp[a][b];
    int x = 0, y = 0;
    for (int a = 0; a < N; a++)
        for (int b = 0; b < 3; b++) {
            for (int c = 0; c < M; c++)
                for (int d = 0; d < 3; d++) {
                    switch (inp[a][c]) {
                    case '.':
                        data[x][y] = titik[b][d];
                        break;
                    case '/':
                        data[x][y] = slash[b][d];
                        break;
                    case '\\':
                        data[x][y] = backs[b][d];
                        break;
                    }
                    y++;
                    y %= M * 3;
                }
            x++;
        }
    for (int a = 0; a < M * 3; a++) {
        if (data[0][a] == '.')
            dfs(0, a);
        if (data[(N * 3) - 1][a] == '.')
            dfs((N * 3) - 1, a);
    }
    for (int a = 0; a < N * 3; a++) {
        if (data[a][0] == '.')
            dfs(a, 0);
        if (data[a][(M * 3) - 1] == '.')
            dfs(a, (M * 3) - 1);
    }
    int ans = 0;
    for (int a = 0; a < N * 3; a++)
        for (int b = 0; b < M * 3; b++)
            if (data[a][b] == '.') {
                dfs(a, b);
                ans++;
            }
    cout << ans << "\n";
}
