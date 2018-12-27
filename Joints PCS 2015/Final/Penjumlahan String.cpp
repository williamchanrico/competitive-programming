#include <bits/stdc++.h>
using namespace std;

string ans = "00";

string sum(char x, char y, int idx)
{
    if (x == '0' && y == '0')
        return (ans[idx - 1] == '0' ? "0" : "1");
    else if (x == '1' && y == '1')
        return (ans[idx - 1] == '0' ? "1" : "0");
    else if (x == '0' && y == '1')
        return (ans[idx - 1] == '0' || ans[idx - 2] == '0' ? "0" : "1");
    else
        return (ans[idx - 1] == '0' && ans[idx - 2] == '0' ? "1" : "0");
}

int main()
{
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    for (int a = 0, b = s1.size() - 1; a < b; a++, b--) {
        swap(s1[a], s1[b]);
        swap(s2[a], s2[b]);
    }

    for (int a = 0, sz = s1.size(); a < sz; a++)
        ans += sum(s1[a], s2[a], a + 2);

    for (int a = ans.size() - 1; a > 1; a--)
        cout << ans[a];

    cout << "\n";
}