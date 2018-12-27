#include <bits/stdc++.h>
using namespace std;

vector<long long> v1, v2;
long long N, inp, ans = 0;

bool cmp(long long x, long long y)
{
    return x > y;
}

int main()
{
    scanf("%lld\n", &N);
    for (int a = 0; a < N; a++) {
        scanf("%lld", &inp);
        v1.push_back(inp);
    }
    for (int a = 0; a < N; a++) {
        scanf("%lld", &inp);
        v2.push_back(inp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), cmp);
    for (int a = 0; a < N; a++)
        ans += v1[a] * v2[a];
    printf("%lld\n", ans);
}