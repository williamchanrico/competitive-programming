#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;

    scanf("%d", &T);
    while (T--) {
        int N;
        int arr[100010];

        scanf("%d", &N);

        int ans = 0;
        bool chaos = false;
        for (int a = 1; a <= N; a++) {
            scanf("%d", &arr[a]);
            if (arr[a] - a > 2)
                chaos = true;

            for (int b = arr[a] - 1; b < a; b++) {
                if (b <= 0)
                    continue;
                ans += (arr[b] > arr[a] ? 1 : 0);
            }
        }

        if (chaos)
            printf("Too chaotic\n");
        else
            printf("%d\n", ans);
    }
}

// 1 2 5 3 7 8 6 4
// 1 2 3 4 5 6 7 8
