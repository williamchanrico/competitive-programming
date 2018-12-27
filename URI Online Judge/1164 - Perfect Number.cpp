#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    long long n;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        long long sum = 0;
        for (long long a = 1; a < n; a++)
            if (n % a == 0) {
                sum += a;
                if (sum > n) {
                    printf("%d nao eh perfeito\n", n);
                    break;
                }
            }
        if (sum == n)
            printf("%d eh perfeito\n", n);
        else if (sum < n)
            printf("%d nao eh perfeito\n", n);
    }
}