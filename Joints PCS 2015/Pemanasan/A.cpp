#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ans = 0;

    scanf("%lld", &n);

    if (n % 2 == 0) {
        ans = (n * (2 + n)) / 4;
        ans -= (n * n) / 4;
    } else {
        ans = ((n * n) - 1) / 4;
        ans -= ((n * n) + 2 * n + 1) / 4;
    }

    printf("%lld\n", ans);
}