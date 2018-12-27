#include <stdio.h>

void proses(int x)
{
    if (x == 1) {
        printf("*\n");
    } else {
        proses(x - 1);
        for (int a = 0; a < x; a++)
            printf("*");
        printf("\n");
        proses(x - 1);
    }
}

int main()
{
    int inp;
    scanf("%d", &inp);
    proses(inp);
}