#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int memo[1 << 12];

int canMove(int idx, int bitmask)
{
    bool right = (idx < 10 && bitmask & (1 << (idx + 1)) && !(bitmask & (1 << (idx + 2))));
    bool left = (idx > 1 && bitmask & (1 << (idx - 1)) && !(bitmask & (1 << idx - 2)));

    if (right & left)
        return 3;
    else if (right)
        return 2;
    else if (left)
        return 1;
    return 0;
}

int dp(int bitmask)
{
    if (memo[bitmask] != -1)
        return memo[bitmask];

    int ans = -INF;

    for (int a = 0; a < 12; a++) {
        if (bitmask & (1 << a)) {
            switch (canMove(a, bitmask)) {
            case 1:
                ans = max(ans, 1 + dp(bitmask & ~(1 << a) & ~(1 << (a - 1)) | (1 << (a - 2))));
                break;
            case 2:
                ans = max(ans, 1 + dp(bitmask & ~(1 << a) & ~(1 << (a + 1)) | (1 << (a + 2))));
                break;
            case 3:
                ans = max(ans,
                    max(1 + dp(bitmask & ~(1 << a) & ~(1 << (a - 1)) | (1 << (a - 2))),
                        1 + dp(bitmask & ~(1 << a) & ~(1 << (a + 1)) | (1 << (a + 2)))));
                break;

            default:
                continue;
            }
        }
    }

    return memo[bitmask] = (ans == -INF ? 0 : ans);
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        char inp[15];
        int bitmask = 0, pRem = 0;

        scanf("%s", inp);

        for (int a = 0; a < strlen(inp); a++) {
            if (inp[a] == 'o') {
                pRem++;
                bitmask |= (1 << a);
            }
        }

        memset(memo, -1, sizeof(memo));

        printf("%d\n", pRem - dp(bitmask));
    }
}
