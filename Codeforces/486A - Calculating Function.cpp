#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;

    scanf("%lld", &N);

    if (N % 2 == 0)
        printf("%lld\n", N / 2);
    else
        printf("%lld\n", -1 * (N + 1) / 2);
}