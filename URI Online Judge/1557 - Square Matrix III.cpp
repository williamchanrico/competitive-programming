#include <bits/stdc++.h>
using namespace std;

int tab[50][50], tabs[50][50];

int num_len(int x)
{
    int n = 0;
    while (x > 0) {
        x /= 10;
        n++;
    }
    return n;
}

void space(int x, int y, int z)
{
    for (int a = 0; a < (tabs[z - 1][z - 1] - tabs[x][y]); a++)
        printf(" ");
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int n = 1;
    for (int a = 0; a < 30; a++) {
        tab[a][0] = tab[0][a] = n;
        tabs[a][0] = tabs[0][a] = num_len(n);
        n *= 2;
    }
    for (int a = 1; a < 30; a++)
        for (int b = 1; b < 30; b++) {
            tab[a][b] = tab[a - 1][b + 1];
            tabs[a][b] = tabs[a - 1][b + 1];
        }

    while (scanf("%d", &n), n) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                space(a, b, n);
                if (b == 0)
                    printf("%d", tab[a][b]);
                else
                    printf(" %d", tab[a][b]);
            }
            printf("\n");
        }
        printf("\n");
    }
}