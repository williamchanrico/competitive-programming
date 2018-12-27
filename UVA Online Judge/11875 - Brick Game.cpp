#include <algorithm>
#include <stdio.h>
using namespace std;

int data[30];

int main()
{
    int T, n;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int a = 0; a < n; a++)
            scanf("%d", &data[a]);
        sort(data, data + n);
        printf("Case %d: %d\n", t, data[n / 2]);
    }
}