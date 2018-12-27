#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

char inp1[110], inp2[110];
int memo[110][110];

int dp(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (memo[x][y] != -1)
        return memo[x][y];
    if (inp1[x] == inp2[y])
        return memo[x][y] = 1 + dp(x - 1, y - 1);

    return memo[x][y] = max(dp(x - 1, y), dp(x, y - 1));
}

int main()
{
    int TC = 1;

    while (fgets(inp1, 110, stdin), inp1[0] != '#') {
        fgets(inp2, 110, stdin);

        memset(memo, -1, sizeof(memo));

        printf("Case #%d: you can visit at most %d cities.\n",
            TC++, dp(strlen(inp1) - 1, strlen(inp2) - 1) - 1);
    }
}