#include <stdio.h>

int main()
{
    int inp;
    int set[] = { 1, 1, 2, 2, 2, 8 };
    int setSize = 6;

    int a;
    for (a = 0; a < setSize; a++) {
        scanf("%d", &inp);

        if (a == setSize - 1)
            printf("%d\n", set[a] - inp);
        else
            printf("%d ", set[a] - inp);
    }
}
