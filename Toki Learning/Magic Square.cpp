#include <stdio.h>

int T;
long long n;

int main()
{
    scanf("%d", &T);
    while (T > 0) {
        scanf("%lld", &n);
        if (n % 2 == 0)
            printf("%lld\n", (n / 2) * ((n * n) + 1));
        else
            printf("%lld\n", (n) * (((n * n) + 1) / 2));
        T--;
    }
}