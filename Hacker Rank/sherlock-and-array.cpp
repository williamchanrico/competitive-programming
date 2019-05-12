#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    int memo[100111];

    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        int inp;
        for (int a = 0; a < n; a++) {
            scanf("%d", &inp);

            if (a == 0)
                memo[a] = inp;
            else
                memo[a] = inp + memo[a - 1];
        }

        // Special cases
        // n == 1: only one input number
        // memo[n - 1] - memo[0] == 0: only one non-zero number at the first index
        // memo[n - 2] == 0: same with above, but at the last index
        if (n == 1 || (memo[n - 1] - memo[0]) == 0 || memo[n - 2] == 0) {
            printf("YES\n");
            continue;
        }

        bool ok = false;
        for (int a = 1; a < n - 1; a++) {
            if (memo[a - 1] == (memo[n - 1] - memo[a])) {
                ok = true;
                break;
            }
        }

        printf("%s\n", (ok ? "YES" : "NO"));
    }
}
