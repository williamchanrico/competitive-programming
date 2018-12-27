#include <algorithm>
#include <stdio.h>

long long x1, x2, y1, y2;

int main()
{
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    printf("%d\n", abs(x2 - x1) + abs(y2 - y1));
}
