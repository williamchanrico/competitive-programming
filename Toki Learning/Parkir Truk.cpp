#include <stdio.h>
#include <string.h>

long long data[105];
long long harga[5];
long long t1, t2, ans = 0;

int main()
{
    memset(data, 0, sizeof(data));
    for (int a = 1; a <= 3; a++)
        scanf("%lld", &harga[a]), harga[a] *= a;
    for (int a = 0; a < 3; a++) {
        scanf("%lld %lld", &t1, &t2);
        for (int a = t1; a < t2; a++)
            data[a]++;
    }
    for (int a = 1; a <= 100; a++)
        ans += harga[data[a]];
    printf("%lld\n", ans);
}
