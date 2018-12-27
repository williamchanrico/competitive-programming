#include <stdio.h>

int n, ans = 1;

int main()
{
    scanf("%d", &n);
    while (ans != 93 && ans <= n) {
        if (ans % 10 != 0)
            printf("%d\n", ans);
        ans++;
    }
    if (n > 92)
        printf("ERROR\n");
}
