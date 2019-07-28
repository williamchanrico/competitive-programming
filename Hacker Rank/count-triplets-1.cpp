#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, R;

    scanf("%d %d", &N, &R);

    int inp;
    long long ans = 0;
    map<long long, long long> m2, m3;
    for (int a = 0; a < N; a++) {
        scanf("%d", &inp);
        ans += m3[inp];
        m3[inp * R] += m2[inp];
        m2[inp * R] += 1;
    }
    printf("%lld\n", ans);
}
