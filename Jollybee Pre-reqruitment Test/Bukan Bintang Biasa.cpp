#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    scanf("%d", &N);

    N /= 2;

    for (int a = -N; a <= N; a++) {
        for (int b = -N; b <= N; b++)
            if (abs(a) == abs(b) || !(a && b))
                printf("*");
            else
                printf(".");

        printf("\n");
    }
}