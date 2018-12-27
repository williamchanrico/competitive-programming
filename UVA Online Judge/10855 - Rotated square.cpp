#include <stdio.h>

int N, n, ans[10];
char data1[1000][1000], data2[1000][1000];

void tes(int x, int y, int z)
{
    for (int a = x, aa = 0; aa < n; a++, aa++)
        for (int b = y, bb = 0; bb < n; b++, bb++) {
            if (data1[a][b] != data2[aa][bb])
                return;
            else if (aa == n - 1 && bb == n - 1)
                ans[z]++;
        }
}

void putar()
{
    char temp[n][n];
    int x = n - 1;
    int y = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            temp[a][b] = data2[x][y];
            x--;
        }
        x = n - 1;
        y++;
    }
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            data2[a][b] = temp[a][b];
}

int main()
{
    ans[0] = ans[1] = ans[2] = ans[3] = 0;
    while (scanf("%d%d", &N, &n), N || n) {
        for (int a = 0; a < N; a++)
            scanf("%s", data1[a]);
        for (int a = 0; a < n; a++)
            scanf("%s", data2[a]);
        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++) {
                if (data1[a][b] == data2[0][0])
                    tes(a, b, 0);
            }
        putar();
        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++) {
                if (data1[a][b] == data2[0][0])
                    tes(a, b, 1);
            }
        putar();
        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++) {
                if (data1[a][b] == data2[0][0])
                    tes(a, b, 2);
            }
        putar();
        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++) {
                if (data1[a][b] == data2[0][0])
                    tes(a, b, 3);
            }
        printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
        ans[0] = ans[1] = ans[2] = ans[3] = 0;
    }
}