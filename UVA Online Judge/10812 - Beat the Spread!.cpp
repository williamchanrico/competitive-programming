#include <stdio.h>

int main()
{
    int T, n, m;

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int a = n, b = 0, line = n / 2; a >= line; a--, b++) {
            if (a - b == m) {
                printf("%d %d\n", a, b);
                a = line - 1;
            }
            if (a == line)
                printf("impossible\n");
        }
    }
}