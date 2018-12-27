#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int M, memo[60000];
vector<int> v(110);

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &M);

        int sum = 0;

        for (int a = 0; a < M; a++) {
            scanf("%d", &v[a]);

            sum += v[a];
        }

        memset(memo, 0, sizeof(memo));

        memo[0] = 1;

        for (int a = 0; a < M; a++)
            for (int b = sum; b >= v[a]; b--)
                memo[b] |= memo[b - v[a]];

        int ans = INF;

        for (int a = 0; a <= sum; a++)
            if (memo[a])
                ans = min(ans, abs(2 * a - sum));

        printf("%d\n", ans);
    }
}