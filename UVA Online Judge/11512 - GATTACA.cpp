#include <bits/stdc++.h>
using namespace std;

int SA[110000], phi[110000], PLCP[110000], LCP[110000];
string str;

bool cmp(int x, int y) { return (str.substr(x) < str.substr(y)); }

void constructSA()
{
    for (int a = 0; a < str.size(); a++)
        SA[a] = a;

    sort(SA, SA + str.size(), cmp);
}

void computeLCP()
{
    int a, L;

    phi[SA[0]] = -1;

    for (a = 1; a < str.size(); a++)
        phi[SA[a]] = SA[a - 1];

    for (a = L = 0; a < str.size(); a++) {
        if (phi[a] == -1) {
            PLCP[a] = 0;

            continue;
        }

        while (str[a + L] == str[phi[a] + L])
            L++;

        PLCP[a] = L;

        L = max(L - 1, 0);
    }

    for (a = 0; a < str.size(); a++)
        LCP[a] = PLCP[SA[a]];
}

int countSubstring(string x, string sub)
{
    int count = 0, pos = 0;

    while ((pos = x.find(sub, pos)) != string::npos) {
        pos++;
        count++;
    }

    return count;
}

int main()
{
    int T;

    cin >> T;

    while (T--) {
        cin >> str;

        constructSA();

        computeLCP();

        int idx, maxi = -1;

        for (int a = 0; a < str.size(); a++) {
            if (maxi < LCP[a]) {
                maxi = LCP[a];
                idx = SA[a];
            }
        }

        if (maxi) {
            string ans = str.substr(idx, maxi);

            cout << ans << " " << countSubstring(str, ans) << "\n";
        } else {
            cout << "No repetitions found!\n";
        }
    }
}