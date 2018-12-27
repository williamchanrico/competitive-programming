#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    while (scanf("%d", &N), N) {
        int K, inp;
        long long ans = 0;
        multiset<int, greater<int>> ms;

        for (int a = 0; a < N; a++) {
            scanf("%d", &K);

            for (int b = 0; b < K; b++) {
                scanf("%d", &inp);

                ms.insert(inp);
            }

            auto first = ms.begin();
            auto last = --ms.end();

            ans += *first - *last;

            ms.erase(first);
            ms.erase(last);
        }

        printf("%lld\n", ans);
    }
}
