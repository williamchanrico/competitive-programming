#include <stdio.h>

int M, N;
int tX, tY, ans = 0, maks = -1;
int graph[50][50];

void runtuh()
{
    for (int a = M - 1; a > -1; a--) {
        for (int b = N - 1; b > -1; b--) {
            if (graph[a][b] == -6) {
                int x = a;
                while (graph[x][b] == -6 && x > -1)
                    x--;
                if (x == -1) {
                    graph[a][b] = -6;
                } else {
                    graph[a][b] = graph[x][b];
                    graph[x][b] = -6;
                }
            }
        }
    }
}

void titik(int x, int y, int z)
{
    if (x < M && x > -1 && y < N && y > -1 && graph[x][y] == z) {
        graph[x][y] = -6;
        titik(x + 1, y, z);
        titik(x - 1, y, z);
        titik(x, y + 1, z);
        titik(x, y - 1, z);
    }
}

void hitung(int x, int y, int z)
{
    if (x < M && x > -1 && y < N && y > -1 && graph[x][y] == z) {
        graph[x][y] = -z;
        ans++;
        hitung(x - 1, y, z);
        hitung(x + 1, y, z);
        hitung(x, y - 1, z);
        hitung(x, y + 1, z);
        if (ans > maks) {
            maks = ans;
            tX = x;
            tY = y;
        }
    }
}

void cetak()
{
    for (int a = 0; a < M; a++) {
        for (int b = 0; b < N; b++)
            if (graph[a][b] != -6)
                if (b == 0)
                    printf("%d", -graph[a][b]);
                else
                    printf(" %d", -graph[a][b]);
            else if (b == 0)
                printf(".");
            else
                printf(" .");
        printf("\n");
    }
}

int main()
{
    scanf("%d%d", &M, &N);
    for (int a = 0; a < M; a++)
        for (int b = 0; b < N; b++)
            scanf("%d", &graph[a][b]);
    for (int a = 0; a < M; a++)
        for (int b = 0; b < N; b++) {
            if (graph[a][b] > 0 && graph[a][b] < 6) {
                hitung(a, b, graph[a][b]);
                ans = 0;
            }
        }
    titik(tX, tY, graph[tX][tY]);
    runtuh();
    cetak();
}
