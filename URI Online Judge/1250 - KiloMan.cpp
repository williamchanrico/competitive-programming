#include <stdio.h>

int main()
{
    int T;
    int n, q[100], hit = 0;
    char w[100];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int a = 0; a < n; a++)
            scanf("%d", &q[a]);
        scanf("%s", w);
        for (int a = 0; a < n; a++) {
            if (q[a] > 2 && w[a] == 'J')
                hit++;
            else if (q[a] < 3 && w[a] == 'S')
                hit++;
        }
        printf("%d\n", hit);
        hit = 0;
    }
}