#include <stdio.h>

int arr[10000];
bool vir = false;

int main()
{
    int n, temp;
    while (scanf("%d", &n), 0 | n) {
        if (vir)
            printf("\n");
        vir = true;
        for (int a = 0; a < n; a++) {
            scanf("%d", &temp);
            arr[a] = temp;
        }
        for (int a = 0; a < n - 5; a++)
            for (int b = a + 1; b < n - 4; b++)
                for (int c = b + 1; c < n - 3; c++)
                    for (int d = c + 1; d < n - 2; d++)
                        for (int e = d + 1; e < n - 1; e++)
                            for (int f = e + 1; f < n; f++)
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
    }
}