#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int C, R, B, P[110], X[110], Y[110], N, ans, memo[101][201][201][2];

int dp(int n, int Crem, int Rrem, int usedDebit)
{
    int cashTime, debitTime;

    cashTime = debitTime = INF;

    if (memo[n][Crem][Rrem][usedDebit] != -1)
        return memo[n][Crem][Rrem][usedDebit];

    if (n == N)
        return 0;

    if (P[n] <= Crem)
        cashTime = X[n] + dp(n + 1, Crem - P[n], Rrem, 0);
    else
        cashTime = INF;

    if (P[n] <= Rrem) {
        int temp = Rrem - P[n];

        if (usedDebit == 1)
            temp = (temp + B > 200 ? 200 : temp + B);

        debitTime = Y[n] + dp(n + 1, Crem, temp, 1);
    }

    return memo[n][Crem][Rrem][usedDebit] = min(cashTime, debitTime);
}

int main()
{
    memset(memo, -1, sizeof(memo));

    cin >> C >> R >> B;
    cin >> N;

    for (int a = 0; a < N; a++)
        cin >> P[a] >> X[a] >> Y[a];

    ans = dp(0, C, R, 0);

    cout << (ans >= INF ? -1 : ans) << "\n";
}