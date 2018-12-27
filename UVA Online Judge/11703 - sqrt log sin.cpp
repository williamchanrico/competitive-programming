#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000

int memo[1100000];

int main()
{
    int N;

    memo[0] = 1;

    for (int a = 1; a <= 1000000; a++) {
        int A = a - sqrt(a);
        int B = floor(log(a));
        int C = a * sin(a) * sin(a);

        memo[a] = (memo[A] + memo[B] + memo[C]) % MOD;
    }

    while (scanf("%d", &N), (N != -1)) {
        printf("%d\n", memo[N]);
    }
}