#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
string inp;
int N, Q, tmp;

int main()
{
    cin >> N >> Q;
    while (N--) {
        cin >> inp >> tmp;
        m[inp] = tmp;
    }
    while (Q--) {
        cin >> inp;
        cout << m[inp] << "\n";
    }
}
