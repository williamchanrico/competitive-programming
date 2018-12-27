#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int A, B, TC = 1;

    while (scanf("%d %d", &A, &B), (A | B)) {
        int adjMat[110][110];

        memset(adjMat, INF, sizeof(adjMat));

        adjMat[A][B] = 1;

        while (scanf("%d %d", &A, &B), (A | B)) {
            adjMat[A][B] = 1;
        }

        for (int a = 1; a <= 100; a++)
            for (int b = 1; b <= 100; b++)
                for (int c = 1; c <= 100; c++)
                    adjMat[b][c] = min(adjMat[b][c], adjMat[b][a] + adjMat[a][c]);

        int sum = 0, count = 0;

        for (int a = 1; a <= 100; a++) {
            for (int b = 1; b <= 100; b++) {
                if (a != b && adjMat[a][b] != INF) {
                    sum += adjMat[a][b];
                    count++;
                }
            }
        }

        printf("Case %d: average length between pages = %.3lf clicks\n", TC++, (double)sum / count);
    }
}
