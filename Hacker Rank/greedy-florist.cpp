#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    int C[110];

    scanf("%d %d", &N, &K);
    for (int a = 0; a < N; a++) {
        scanf("%d", &C[a]);
    }

    sort(C, C + N, greater<int>());

    int ans = 0;
    for (int a = 0; a < N; a++) {
        ans += (C[a] * ((int)(a / K) + 1));
    }
    printf("%d\n", ans);
}
