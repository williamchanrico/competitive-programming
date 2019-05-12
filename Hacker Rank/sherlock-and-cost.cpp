#include <bits/stdc++.h>
using namespace std;

int B[100111], memo[100111][2];

// prev 0 = took the minimum
// prev 1 = took the maximum
int dp(int idx, int prev, int n)
{
    if (idx >= n)
        return 0;

    if (memo[idx][prev] != -1)
        return memo[idx][prev];

    int previousNum = (prev ? B[idx - 1] : 1);
    return memo[idx][prev] = max(abs(previousNum - 1) + dp(idx + 1, 0, n),
               abs(previousNum - B[idx]) + dp(idx + 1, 1, n));
}

int main()
{
    int t;

    scanf("%d", &t);
    while (t--) {
        int n;

        scanf("%d", &n);
        for (int a = 0; a < n; a++) {
            scanf("%d", &B[a]);
        }

        memset(memo, -1, sizeof(memo));

        printf("%d\n", max(dp(1, 0, n), dp(1, 1, n)));
    }
}
