#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;

    scanf("%d", &T);
    while (T--) {
        int N, prices[51000];

        scanf("%d", &N);
        for (int a = N - 1; a >= 0; a--) {
            scanf("%d", &prices[a]);
        }

        int maxi = -1;
        long long ans = 0;
        for (int a = 0; a < N; a++) {
            maxi = max(maxi, prices[a]);
            ans += maxi - prices[a];
        }

        printf("%lld\n", ans);
    }
}
