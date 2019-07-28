#include <algorithm>
#include <cstdio>
#include <map>

int main()
{
    int N;

    scanf("%d", &N);

    int arr[110];
    std::map<int, int> m;
    for (int a = 0; a < N; a++) {
        scanf("%d", &arr[a]);
        ++m[arr[a]];
    }

    std::sort(arr, arr + N);

    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        ans += (int)(it->second / 2);
    }
    printf("%d\n", ans);
}
