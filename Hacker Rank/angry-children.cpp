#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    int arr[100010];
    for (int a = 0; a < N; a++) {
        scanf("%d", &arr[a]);
    }
    sort(arr, arr + N);

    int ans = INF;
    for (int a = K - 1; a < N; a++) {
        int maxi = -INF;
        int mini = INF;

        for (int b = a - K + 1; b <= a; b++) {
            maxi = max(maxi, arr[b]);
            mini = min(mini, arr[b]);
        }

        ans = min(ans, maxi - mini);
    }

    printf("%d\n", ans);
}
