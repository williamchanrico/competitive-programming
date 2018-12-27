#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int N, M, inp, mini, ans = -1;

    scanf("%d %d", &N, &M);

    for (int a = 0; a < N; a++) {
        mini = INF;

        for (int b = 0; b < M; b++) {
            scanf("%d", &inp);

            mini = min(mini, inp);
        }

        ans = max(ans, mini);
    }

    printf("%d\n", ans);
}