#include <stdio.h>
#include <string.h>

const int kMod = 1e9 + 7;

char str[200001];
long long memo[200001];

long long dp(int i)
{
    if (i <= 0)
        return 0;
    if (memo[i] != -1)
        return memo[i];
    return memo[i] = (((10 * dp(i - 1)) % kMod) + (i * (str[i - 1] - '0')) % kMod) % kMod;
}

int main()
{
    scanf("%s", str);

    memset(memo, -1, sizeof(memo));

    long long ans = 0;
    for (size_t a = 1, len = strlen(str); a <= len; a++) {
        ans = (ans + dp(a)) % kMod;
    }

    printf("%lld\n", ans);
}

/*

#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

int substrings(string n)
{
    long long total = n[0] - '0';
    long long ans = total;

    for (size_t a = 1, len = n.size(); a < len; a++) {
        total = (((total * 10) % kMod) + ((a + 1) * (n[a] - '0')) % kMod) % kMod;
        ans = (ans + total) % kMod;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

*/
