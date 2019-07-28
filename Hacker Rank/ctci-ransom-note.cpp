#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;

    cin >> M >> N;

    string inp;
    map<string, int> m;
    for (int a = 0; a < M; a++) {
        cin >> inp;
        ++m[inp];
    }

    bool yes = true;
    for (int a = 0; a < N; a++) {
        cin >> inp;
        if (yes && m.find(inp) != m.end() && m[inp] != 0) {
            --m[inp];
        } else {
            yes = false;
        }
    }
    cout << (yes ? "Yes" : "No") << endl;
}
