#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int N, offset, L, R, A[510], memo[510][300000];

int dp(int idx, int pos)
{
    if (idx == N)
        return ((pos - offset >= L) && (pos - offset <= R));
    if (memo[idx][pos] != -1)
        return memo[idx][pos];

    return memo[idx][pos] = ((dp(idx + 1, pos + A[idx]) % MOD) + (dp(idx + 1, pos - A[idx]) % MOD)) % MOD;
}

int main()
{
    scanf("%d", &N);

    offset = 0;

    for (int a = 0; a < N; a++) {
        scanf("%d", &A[a]);

        offset += A[a];
    }

    scanf("%d %d", &L, &R);

    memset(memo, -1, sizeof(memo));

    printf("%d\n", dp(0, 0 + offset));
}
