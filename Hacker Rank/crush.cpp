#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    vector<int> arr(10000010, 0);

    scanf("%d %d", &N, &M);

    int A, B, K;
    for (int a = 0; a < M; a++) {
        scanf("%d %d %d", &A, &B, &K);
        arr[A] += K;
        if (B < N)
            arr[B + 1] -= K;
    }

    long long sum = 0;
    long long ans = 0;
    for (int a = 1; a <= N; a++) {
        sum += arr[a];
        ans = max(ans, sum);
    }
    printf("%lld\n", ans);
}
