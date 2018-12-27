#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X[2100], Y[2100];

    scanf("%d", &N);

    bitset<2100000> bs;

    bs.set();

    for (int a = 0; a < N; a++) {
        scanf("%d", &X[a]);

        bs[X[a]] = 0;
    }

    for (int a = 0; a < N; a++) {
        scanf("%d", &Y[a]);

        bs[Y[a]] = 0;
    }

    int ans = 0;

    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++)
            if (!bs[X[a] ^ Y[b]])
                ans++;

    if (ans % 2)
        printf("Koyomi\n");
    else
        printf("Karen\n");
}
