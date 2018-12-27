#include <bits/stdc++.h>
using namespace std;

long long memo[310][310][1100];

long long dp(int coin, int sum, int count)
{
    if (coin < 1 || sum < 0 || count < 0)
        return 0;
    if (sum == 0)
        return (count == 0);
    if (memo[coin][sum][count] != -1)
        return memo[coin][sum][count];

    return memo[coin][sum][count] = dp(coin - 1, sum, count)
        + dp(coin, sum - coin, count - 1);
}

int main()
{
    string inp;
    int N[3], lo, hi;

    memset(memo, -1, sizeof(memo));

    while (getline(cin, inp)) {
        int count = 0;
        stringstream ss;

        for (ss << inp; ss >> N[count]; count++)
            ;

        lo = (count == 3 ? N[1] : 0);
        hi = N[count - 1];

        long long ans = 0;

        for (int a = lo; a <= hi; a++)
            ans += dp(300, N[0], a);

        printf("%lld\n", ans);
    }
}
