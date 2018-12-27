#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    for (int a = n; a > 0; a--)
        if (n % a == 0)
            printf("%d\n", a);
}
