#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int memo[5010][5010];

int lcs(int x, int y)
{

    if (x < 0 || y < 0)
        return 0;
    if (memo[x][y] != -1)
        return memo[x][y];
    if (s1[x] == s2[y])
        return memo[x][y] = 1 + lcs(x - 1, y - 1);
    return memo[x][y] = max(lcs(x - 1, y), lcs(x, y - 1));
}

int main()
{
    getline(cin, s1);
    getline(cin, s2);

    memset(memo, -1, sizeof(memo));
    cout << lcs(s1.size() - 1, s2.size() - 1) << endl;
}
