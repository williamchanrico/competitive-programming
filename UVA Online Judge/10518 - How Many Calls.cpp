#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;

long long MOD = 1000000009, K = 3;

Matrix multiply(const Matrix& x, const Matrix& y)
{
    Matrix ans(K + 1, vector<long long>(K + 1));

    for (int a = 1; a <= K; a++)
        for (int b = 1; b <= K; b++)
            for (int c = 1; c <= K; c++)
                ans[a][b] = (ans[a][b] + x[a][c] * y[c][b]) % MOD;

    return ans;
}

Matrix pow(const Matrix& x, long long p)
{
    if (p == 1)
        return x;
    if (p % 2)
        return multiply(x, pow(x, p - 1));

    Matrix squared = pow(x, p / 2);

    return multiply(squared, squared);
}

long long f(long long x)
{
    vector<long long> F1(K + 1);

    F1[0] = 1;
    F1[1] = 1;
    F1[2] = 3;
    F1[3] = 1;

    Matrix T(K + 1, vector<long long>(K + 1));
    T[1][1] = 0, T[1][2] = 1, T[1][3] = 0;
    T[2][1] = 1, T[2][2] = 1, T[2][3] = 1;
    T[3][1] = 0, T[3][2] = 0, T[3][3] = 1;

    if (x <= 2)
        return F1[x] % MOD;

    T = pow(T, x - 1);

    long long ans = 0;

    for (int a = 1; a <= K; a++)
        ans = (ans + T[1][a] * F1[a]) % MOD;

    return ans;
}

int main()
{
    int TC = 0;
    long long N, B;

    while (scanf("%lld %lld", &N, &B), (N | B)) {
        MOD = B;

        printf("Case %d: %lld %lld %lld\n", ++TC, N, B, f(N));
    }
}