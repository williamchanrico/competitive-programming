#include <stdio.h>

char graph[1000][1000];
int n, m, size_K = 0, size_B = 0;

void dfs(int x, int y, char z)
{
    if (graph[x][y] != '#' && graph[x][y] != '+' && x > -1 && y > -1 && x < n && y < m) {
        graph[x][y] = '+';
        if (z == 'K') {
            size_K++;
            dfs(x, y - 1, 'K');
            dfs(x, y + 1, 'K');
            dfs(x - 1, y, 'K');
            dfs(x + 1, y, 'K');
        } else {
            size_B++;
            dfs(x, y - 1, 'B');
            dfs(x, y + 1, 'B');
            dfs(x - 1, y, 'B');
            dfs(x + 1, y, 'B');
        }
    }
}

int main()
{
    bool found_B = false;
    scanf("%d%d", &m, &n);
    for (int a = 0; a < n; a++)
        scanf("%s", graph[a]);
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            if (graph[a][b] == 'K') {
                dfs(a, b, 'K');
                a = n;
                b = m;
            }
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++) {
            if (graph[a][b] == 'B') {
                found_B = true;
                dfs(a, b, 'B');
                a = n;
                b = m;
            }
        }
    if (found_B) {
        if (size_K > size_B)
            printf("K %d\n", size_K - size_B);
        else if (size_K < size_B)
            printf("B %d\n", size_B - size_K);
        else
            printf("SERI\n");
    } else {
        printf("SERI\n");
    }
}
