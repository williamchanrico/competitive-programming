#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int N, memoLis[10000], memoLds[10000];
vector<int> vH(10000), vL(10000);

void dpLis()
{
    for (int a = N - 1; a >= 0; a--) {
        memoLis[a] = vL[a];

        for (int b = a + 1; b < N; b++)
            if (vH[a] < vH[b])
                memoLis[a] = max(memoLis[a], vL[a] + memoLis[b]);
    }
}

void dpLds()
{
    for (int a = N - 1; a >= 0; a--) {
        memoLds[a] = vL[a];

        for (int b = a + 1; b < N; b++)
            if (vH[a] > vH[b])
                memoLds[a] = max(memoLds[a], vL[a] + memoLds[b]);
    }
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int TC = 1; TC <= T; TC++) {
        scanf("%d", &N);

        for (int a = 0; a < N; a++)
            scanf("%d", &vH[a]);

        for (int a = 0; a < N; a++)
            scanf("%d", &vL[a]);

        int maxLis = -INF, maxLds = -INF;

        dpLis();
        dpLds();

        for (int a = 0; a < N; a++) {
            maxLis = max(maxLis, memoLis[a]);
            maxLds = max(maxLds, memoLds[a]);
        }

        if (maxLis >= maxLds)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", TC, maxLis, maxLds);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", TC, maxLds, maxLis);
    }
}