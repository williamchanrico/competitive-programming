#include <stdio.h>
#include <string.h>

int data[1010];

int cheat(int x)
{
    if (x < 5)
        data[x] = x;
    if (data[x] != -1)
        return data[x];
    data[x] = cheat(x / 2) + cheat(x / 3) + cheat(x / 4);
    if (data[x] < x)
        data[x] = x;
    return data[x];
}

int main()
{
    memset(data, -1, sizeof(data));
    int n;
    scanf("%d", &n);
    printf("%d\n", cheat(n));
}