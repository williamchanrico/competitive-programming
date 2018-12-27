#include <stdio.h>

int main()
{
    long long T, n, ans;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        long long temp = n;
        while (temp % 4 != 0)
            temp--;
        ans = (temp / 4) * (4 + temp) / 2;
        temp = n;
        while (temp % 7 != 0)
            temp--;
        ans += ((temp / 7) * (7 + temp) / 2);
        temp = n;
        while (temp % 28 != 0 && temp > 27)
            temp--;
        ans -= ((temp / 28) * (28 + temp) / 2);
        printf("%lld\n", ans);
        ans = 0;
    }
}