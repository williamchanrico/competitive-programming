#include <bits/stdc++.h>
using namespace std;

long long modPow(long long x, long long y, long long m)
{
    long long ans = 1;

    while (y > 0) {
        if (y % 2)
            ans = (ans * x) % m;

        y >>= 1;

        x = (x * x) % m;
    }

    return ans;
}

int main()
{
    int C;

    scanf("%d", &C);

    while (C--) {
        long long X, Y, N;

        scanf("%lld %lld %lld", &X, &Y, &N);

        printf("%lld\n", modPow(X, Y, N));
    }

    scanf("%*d");
}
