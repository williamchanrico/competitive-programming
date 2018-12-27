#include <stdio.h>

int st, x, y, z, ans = 0;

int main()
{
    scanf("%d%d%d%d", &st, &x, &y, &z);
    while ((st + x + y + z) != 0) {
        ans = 120;
        if (st > x)
            ans += st - x;
        else
            ans += 40 - (x - st);
        if (x < y)
            ans += y - x;
        else
            ans += 40 - (x - y);
        if (y < z)
            ans += 40 - (z - y);
        else
            ans += y - z;
        printf("%d\n", ans * 9);
        scanf("%d%d%d%d", &st, &x, &y, &z);
    }
}