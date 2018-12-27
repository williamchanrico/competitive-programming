#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool t[255][255];
    int R, C, K, r, c;

    for (int a = 0; a < 255; a++)
        for (int b = 0; b < 255; b++)
            t[a][b] = true;

    scanf("%d %d %d", &R, &C, &K);

    for (int a = 0; a < K; a++) {
        scanf("%d %d", &r, &c);
        t[r][c] = false;
    }

    for (int a = 1; a <= R; a++) {
        for (int b = 1; b <= C; b++)
            if (t[a][b])
                printf("/\\");
            else
                printf("__");

        printf("\n");
    }
}