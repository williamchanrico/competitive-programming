#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000

long long N, memo[1000010];

int main()
{
    memset(memo, -1, sizeof(memo));
    memo[1] = 1;
    memo[2] = 2;
    cin >> N;
    for (int a = 3; a <= N; a++)
        memo[a] = (memo[a - 1] + memo[a - 2]) % MOD;
    cout << memo[N] << "\n";
}