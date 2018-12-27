#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X, Y, sumX = 0, sumY = 0;
    ;
    bool canRotate = false;

    scanf("%d", &N);

    for (int a = 0; a < N; a++) {
        scanf("%d %d", &X, &Y);

        if ((X % 2) ^ (Y % 2)) {
            canRotate = true;
        }

        sumX += X;
        sumY += Y;
    }

    if ((sumX % 2) ^ (sumY % 2)) {
        printf("-1\n");
    } else if ((sumX % 2 == 0) && (sumY % 2 == 0)) {
        printf("0\n");
    } else {
        printf("%d\n", canRotate ? 1 : -1);
    }
}