#include <bits/stdc++.h>
using namespace std;

#define COIN_COUNT 5

int N, memo[10][7500], coin[] = { 1, 5, 10, 25, 50 };

int dp(int idx, int val)
{
    if (val == 0)
        return 1;
    if (val < 0 || idx == COIN_COUNT)
        return 0;
    if (memo[idx][val] != -1)
        return memo[idx][val];

    return memo[idx][val] = dp(idx + 1, val) + dp(idx, val - coin[idx]);
}

int main()
{
    memset(memo, -1, sizeof(memo));

    while (scanf("%d", &N) != EOF) {
        printf("%d\n", dp(0, N));
    }
}