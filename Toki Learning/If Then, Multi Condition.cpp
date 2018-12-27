#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    if (n % 2 == 0 && n > 0)
        printf("%d\n", n);
}
