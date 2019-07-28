#include <bits/stdc++.h>
using namespace std;

#define IJ_SIZE 6
#define INF 0x3f3f3f3f

int main()
{
    int ans = -INF;
    int arr[10][10] = {};

    for (int a = 0; a < IJ_SIZE; a++) {
        for (int b = 0; b < IJ_SIZE; b++) {
            scanf("%d", &arr[a][b]);

            if (a >= 2 && b >= 2) {
                int hourglass = arr[a][b] + arr[a][b - 1] + arr[a][b - 2] + arr[a - 1][b - 1] + arr[a - 2][b] + arr[a - 2][b - 1] + arr[a - 2][b - 2];
                ans = max(ans, hourglass);
            }
        }
    }
    printf("%d\n", ans);
}
