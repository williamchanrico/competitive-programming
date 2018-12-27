#include <algorithm>
#include <stdio.h>

int jml, data[2000005];
double ans = 0;

int main()
{
    scanf("%d", &jml);
    for (int a = 0; a < jml; a++)
        scanf("%d", &data[a]);
    std::sort(data, data + jml);
    if (jml % 2 == 0)
        ans = ((double)data[jml / 2] + (double)data[jml / 2 - 1]) / 2;
    else
        ans = data[jml / 2];
    printf("%.2lf\n", ans);
}