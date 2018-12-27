#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N;
    long long ans;

    scanf("%d", &T);

    while (T--) {
        ans = 0;

        scanf("%d", &N);

        for (int a = 1; a * a <= N; a++) {
            if (N % a == 0) {
                ans += a;

                if (a != N / a)
                    ans += N / a;
            }
        }

        printf("%lld\n", ans);
    }
}
