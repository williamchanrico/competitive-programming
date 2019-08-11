#include <bits/stdc++.h>
using namespace std;

typedef struct Data {
    int L = 0;
    int T = 0;
} Contest;

bool cmp(const Contest& left, const Contest& right)
{
    if (left.T == right.T)
        return left.L > right.L;
    return left.T > right.T;
}

int main()
{
    auto N = 0;
    auto K = 0;

    scanf("%d %d", &N, &K);

    Contest con[10010];
    for (int a = 0; a < N; a++) {
        scanf("%d %d", &con[a].L, &con[a].T);
    }

    sort(con, con + N, cmp);

    int ans = 0;
    for (int a = 0; a < N; a++) {
        if (a < K) {
            ans += con[a].L;
            continue;
        }

        ans += (con[a].T == 1 ? -con[a].L : con[a].L);
    }
    printf("%d\n", ans);
}
