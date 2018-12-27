#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int memo[110][110];
char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

int dp(int count, int slots)
{
    if (count == 0)
        return 1;
    if (slots == 0)
        return 0;
    if (memo[count][slots] != -1)
        return memo[count][slots];

    memo[count][slots] = 0;

    for (int a = 0; a <= count; a++)
        memo[count][slots] = (memo[count][slots] + dp(a, slots - 1)) % MOD;

    return memo[count][slots];
}

int getIdx(char x)
{
    for (int a = 0; a < 5; a++)
        if (x == vowel[a])
            return a;
    return -1;
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        char G[30];
        int count[5], slots[5] = {};

        for (int a = 0; a < 5; a++)
            scanf("%d", &count[a]);

        scanf("%s", G);

        for (int a = 0, len = strlen(G); a < len; a++) {
            if (getIdx(G[a]) != -1) {
                count[getIdx(G[a])]--;
                slots[getIdx(G[a])]++;
            }
        }

        int ans = 1;

        memset(memo, -1, sizeof(memo));

        for (int a = 0; a < 5; a++)
            if (slots[a])
                ans = (ans * dp(count[a], slots[a])) % MOD;

        printf("%d\n", ans);
    }
}
