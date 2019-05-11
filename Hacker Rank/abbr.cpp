#include <bits/stdc++.h>
using namespace std;

int memo[1010][1010];
string initial, target;

int dp(int x, int y)
{
    if (x < 0 && y < 0)
        return 1;

    if (x < 0) {
        return 0;
    }

    if (y < 0) {
        if (islower(initial[x]))
            return dp(x - 1, y);
        return 0;
    }

    if (memo[x][y] != -1)
        return memo[x][y];

    if (islower(initial[x])) {
        if (toupper(initial[x]) == toupper(target[y]))
            return memo[x][y] = dp(x - 1, y - 1) || dp(x - 1, y);
        return memo[x][y] = dp(x - 1, y);
    } else {
        if (initial[x] == target[y])
            return memo[x][y] = dp(x - 1, y - 1);
        return memo[x][y] = 0;
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--) {
        memset(memo, -1, sizeof(memo));

        cin >> initial >> target;
        cout << (dp(initial.size() - 1, target.size() - 1) == 1 ? "YES" : "NO") << endl;
    }
}
