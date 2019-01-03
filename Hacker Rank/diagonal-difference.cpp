#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, temp, ans = 0;

    scanf("%d", &N);
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            scanf("%d", &temp);

            if (N % 2 == 1 && a == (N / 2))
                continue;

            // ans += (a - b == 0 ? temp : ((a + b == (N - 1)) ? -temp : 0));
            if (a - b == 0) {
                ans += temp;
            } else if (a + b == (N - 1)) {
                ans -= temp;
            }
        }
    }

    printf("%d\n", abs(ans));
}
