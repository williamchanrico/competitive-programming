#include <stdio.h>

long long n, m, ans = 0, data[100], total;
int counter = 0;

int main()
{
    scanf("%lld%lld", &n, &m);
    total = m - n;
    if (total == 0) {
        printf("0\n");
        return 0;
    }
    for (long long a = 1; a <= total; a *= 2, counter++)
        data[counter] = a;
    counter--;
    while (ans < total) {
        if (ans + data[counter] <= total) {
            printf("%lld\n", data[counter]);
            ans += data[counter];
            counter--;
        } else {
            counter--;
        }
    }
}