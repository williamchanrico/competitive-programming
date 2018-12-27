#include <bits/stdc++.h>
using namespace std;

string inp1, inp2;
int memo[1010][1010];

int lcs(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (memo[x][y] != -1)
        return memo[x][y];
    if (inp1[x] == inp2[y])
        return memo[x][y] = 1 + lcs(x - 1, y - 1);
    return memo[x][y] = max(lcs(x - 1, y), lcs(x, y - 1));
}

int main()
{
    while (getline(cin, inp1)) {
        getline(cin, inp2);
        memset(memo, -1, sizeof(memo));
        cout << lcs(inp1.size() - 1, inp2.size() - 1) << "\n";
    }
}