#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    for (int a = 1; a <= (n / 2) + 1; a++) {
        for (int b = 0; b <= (n / 2) - a; b++)
            printf("*");
        for (int b = 0; b < (2 * a) - 1; b++)
            printf("D");
        for (int b = 0; b <= (n / 2) - a; b++)
            printf("*");
        printf("\n");
    }
    for (int a = (n / 2); a >= 1; a--) {
        for (int b = 0; b <= (n / 2) - a; b++)
            printf("*");
        for (int b = 0; b < (2 * a) - 1; b++)
            printf("D");
        for (int b = 0; b <= (n / 2) - a; b++)
            printf("*");
        printf("\n");
    }
}