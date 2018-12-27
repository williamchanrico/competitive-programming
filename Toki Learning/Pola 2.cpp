#include <stdio.h>

int n, x = 0;

int main()
{
    scanf("%d", &n);
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= a; b++) {
            printf("%d", x++);
            x %= 10;
        }
        printf("\n");
    }
}
