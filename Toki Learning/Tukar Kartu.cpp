#include <stdio.h>

int data[10005], n, ans = 0;

int main()
{
    scanf("%d", &n);
    for (int a = 0; a < n; a++)
        scanf("%d", &data[a]);
    for (int a = 0; a < n; a++)
        for (int b = a + 1; b < n; b++)
            if (data[a] > data[b])
                ans++;
    printf("%d\n", ans);
}