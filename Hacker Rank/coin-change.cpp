#include <bits/stdc++.h>

using namespace std;

int coin[100];
long long memo[500][3000];

long long dp(int idx, int total)
{
    if (total == 0)
        return 1;
    if (memo[idx][total] != -1)
        return memo[idx][total];
    if (idx < 1 || total < 0)
        return 0;

    return memo[idx][total] = dp(idx, total - coin[idx]) + dp(idx - 1, total);
}

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    for (int a = 1; a <= M; a++) {
        scanf("%d", &coin[a]);
    }

    memset(memo, -1, sizeof(memo));
    printf("%lld\n", dp(M, N));
}
