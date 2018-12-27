#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        map<int, int> m;
        int N, inp, ans = 0, startIdx = 0;

        scanf("%d", &N);

        for (int a = 0; a < N; a++) {
            scanf("%d", &inp);

            if (m.count(inp) && m[inp] >= startIdx) {
                ans = max(ans, a - startIdx);
                startIdx = m[inp] + 1;
            }

            m[inp] = a;
        }

        ans = max(ans, N - startIdx);

        printf("%d\n", ans);
    }
}