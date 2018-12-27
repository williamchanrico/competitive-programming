#include <bits/stdc++.h>
using namespace std;

int N, K, memo[110][110];

int dp(int total, int count)
{
    if (total > N)
        return 0;
    if (count == K)
        return (total == N);
    if (memo[total][count] != -1)
        return memo[total][count];

    memo[total][count] = 0;

    for (int a = 0; a <= N; a++)
        memo[total][count] = (memo[total][count] + dp(total + a, count + 1)) % 1000000;

    return memo[total][count];
}

int main()
{
    while (scanf("%d %d", &N, &K), (N | K)) {
        memset(memo, -1, sizeof(memo));

        printf("%d\n", dp(0, 0));
    }
}