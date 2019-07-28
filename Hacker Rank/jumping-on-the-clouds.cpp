#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int arr[110], memo[110];

int dp(int idx)
{
    if (idx <= 0)
        return INF;
    if (idx == 1)
        return 0;
    if (memo[idx] != -1)
        return memo[idx];
    if (arr[idx] == 1)
        return INF;
    return memo[idx] = 1 + min(dp(idx - 1), dp(idx - 2));
}

int main()
{
    int N;

    scanf("%d", &N);

    for (int a = N; a > 0; a--)
        scanf("%d", &arr[a]);
    assert(arr[0] != 1);

    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(N));
}
