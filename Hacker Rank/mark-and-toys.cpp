#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    vector<int> v(N);

    for (int a = 0; a < N; a++) {
        scanf("%d", &v[a]);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int a = 0; a < N && K > 0; a++) {
        ans += (v[a] <= K ? 1 : 0);
        K -= v[a];
    }
    printf("%d\n", ans);
}
