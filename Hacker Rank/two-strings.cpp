#include <bits/stdc++.h>
using namespace std;

int main()
{
    int P;

    cin >> P;

    string s1, s2;
    while (P--) {
        cin >> s1 >> s2;

        set<char> set1(s1.begin(), s1.end());

        size_t exists = string::npos;
        for (auto it = set1.begin(); it != set1.end(); it++) {
            if ((exists = s2.find(*it)) != string::npos) {
                break;
            }
        }
        if (exists != string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
