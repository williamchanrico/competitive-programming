#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> v;

int main()
{
    cin >> n >> q;
    while (n > 0) {
        v.push_back(n % q);
        n /= q;
    }
    for (int a = v.size() - 1; a > -1; a--)
        cout << v[a];
    cout << "\n";
}
