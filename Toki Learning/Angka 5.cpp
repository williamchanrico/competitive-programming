#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, q, tmp, inp;

int main()
{
    cin >> n >> q >> tmp;
    for (int a = n + q; a > 0; a--) {
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(), v.end());
    cout << v[tmp - 1] << "\n";
}