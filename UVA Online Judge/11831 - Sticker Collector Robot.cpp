#include <bits/stdc++.h>
using namespace std;

char grid[110][110], cmd[51000];
int N, M, S, posX, posY, orient;

int run()
{
    int ans = 0, X, Y;
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    for (int a = 0; a < S; a++) {

        if (cmd[a] == 'D') {
            orient = (orient + 1) % 4;
        } else if (cmd[a] == 'E') {
            orient = (orient - 1 + 4) % 4;
        } else {
            X = posX + dx[orient];
            Y = posY + dy[orient];

            if (X >= 0 && X < N && Y >= 0 && Y < M && grid[X][Y] != '#') {

                if (grid[X][Y] == '*') {
                    ans++;
                    grid[X][Y] = '.';
                }

                posX = X;
                posY = Y;
            }
        }
    }

    return ans;
}

int main()
{
    while (scanf("%d %d %d", &N, &M, &S), N + M + S) {

        for (int a = 0; a < N; a++) {
            scanf("%s", grid[a]);

            for (int b = 0; b < M; b++) {
                if (grid[a][b] != '*' && grid[a][b] != '.' && grid[a][b] != '#') {
                    posX = a;
                    posY = b;
                }
            }
        }

        if (grid[posX][posY] == 'N')
            orient = 0;
        else if (grid[posX][posY] == 'S')
            orient = 2;
        else if (grid[posX][posY] == 'L')
            orient = 1;
        else
            orient = 3;

        scanf("%s", cmd);

        printf("%d\n", run());
    }
}
