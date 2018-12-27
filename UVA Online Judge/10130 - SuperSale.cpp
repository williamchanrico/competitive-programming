#include <bits/stdc++.h>
using namespace std;

int T, N, maxW, G, V[1100], W[1010], memo[1100][40];

int dp(int idx, int remW)
{
    if (idx == N || remW == 0)
        return 0;
    if (memo[idx][remW] != -1)
        return memo[idx][remW];
    if (remW < W[idx])
        return memo[idx][remW] = dp(idx + 1, remW);

    return memo[idx][remW] = max(dp(idx + 1, remW), V[idx] + dp(idx + 1, remW - W[idx]));
}

int main()
{
    scanf("%d", &T);

    while (T--) {

        scanf("%d", &N);

        memset(memo, -1, sizeof(memo));

        for (int a = 0; a < N; a++)
            scanf("%d %d", &V[a], &W[a]);

        int ans = 0;

        scanf("%d", &G);

        while (G--) {
            scanf("%d", &maxW);

            ans += dp(0, maxW);
        }

        printf("%d\n", ans);
    }
}