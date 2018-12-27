#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int N, A[110000], memoBefore[110000], memoAfter[110000];

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        int ans = INF;

        scanf("%d", &N);

        for (int a = 0; a < N; a++)
            scanf("%d", &A[a]);

        if (N <= 3) {
            for (int a = 0; a < N; a++)
                ans = min(ans, A[a]);

            printf("%d\n", ans);

            continue;
        }

        memoBefore[0] = memoBefore[1] = memoBefore[2] = 1;

        for (int a = 3; a <= N; a++)
            memoBefore[a] = (memoBefore[a - 1] && (A[a - 1] - A[a - 2] == A[a - 2] - A[a - 3]));

        memoAfter[N] = memoAfter[N - 1] = memoAfter[N - 2] = 1;

        for (int a = N - 3; a >= 0; a--)
            memoAfter[a] = (memoAfter[a + 1] && (A[a + 1] - A[a] == A[a + 2] - A[a + 1]));

        if (memoAfter[1]) {

            ans = min(ans, A[0]);
        }

        if (memoBefore[N - 1]) {

            ans = min(ans, A[N - 1]);
        }

        if (memoAfter[2] && A[2] - A[0] == A[3] - A[2]) {

            ans = min(ans, A[1]);
        }

        if (memoBefore[N - 2] && A[N - 1] - A[N - 3] == A[N - 3] - A[N - 4]) {

            ans = min(ans, A[N - 2]);
        }

        for (int a = 2; a < N - 2; a++) {
            int delta = A[a - 1] - A[a - 2];

            if (memoBefore[a] && memoAfter[a + 1] && (A[a + 1] - A[a - 1] == delta))
                ans = min(ans, A[a]);
        }

        printf("%d\n", (ans == INF ? -1 : ans));
    }
}
