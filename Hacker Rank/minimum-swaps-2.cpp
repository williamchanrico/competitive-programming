#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int arr[100010];
    map<int, int> m;

    scanf("%d", &N);
    for (int a = 1; a <= N; a++) {
        scanf("%d", &arr[a]);
        m[arr[a]] = a;
    }

    int ans = 0;
    for (int a = 1; a <= N; a++) {
        if (arr[a] != a) {
            ++ans;
            swap(arr[a], arr[m[a]]);
            m[arr[m[a]]] = m[a];
        }
    }

    printf("%d\n", ans);
}
