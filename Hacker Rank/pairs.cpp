#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    set<int> s;
    int ans = 0;
    for (int a = 0; a < N; a++) {
        int inp;
        scanf("%d", &inp);
        ans += s.count(inp - K);
        ans += s.count(inp + K);
        s.insert(inp);
    }
    printf("%d\n", ans);
}

// int main()
// {
//     int N, K;

//     scanf("%d %d", &N, &K);

//     vector<int> v(N, 0);

//     for (int a = 0; a < N; a++) {
//         scanf("%d", &v[a]);
//     }
//     sort(v.begin(), v.end());

//     int i = 0, j = 1, ans = 0;
//     while (j < N) {
//         int diff = v[j] - v[i];
//         if (diff == K) {
//             ++ans;
//             ++j;
//         } else if (diff < K) {
//             ++j;
//         } else if (diff > K) {
//             ++i;
//         }
//     }
//     printf("%d\n", ans);
// }
