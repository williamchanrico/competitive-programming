#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    scanf("%d", &N);

    int arr[100010] = { 0 };
    for (int a = 0; a < N; a++) {
        scanf("%d", &arr[a]);
    }

    sort(arr, arr + N);

    int ans = 0x3f3f3f3f;
    for (int a = 0; a < N - 1; a++)
        ans = min(ans, abs(arr[a + 1] - arr[a]));
    printf("%d\n", ans);
}
