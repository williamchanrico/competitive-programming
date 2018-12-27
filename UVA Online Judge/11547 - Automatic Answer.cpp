#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", abs((((((n * 567 / 9) + 7492) * 235 / 47) - 498) / 10) % 10));
    }
}