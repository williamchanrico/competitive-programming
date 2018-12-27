#include <bits/stdc++.h>
using namespace std;

int main()
{
    int data[5];
    vector<int> v;
    for (int a = 0; a < 3; a++) {
        cin >> data[a];
        v.push_back(data[a]);
    }
    sort(v.begin(), v.end());
    for (int a = 0; a < 3; a++)
        cout << v[a] << "\n";
    cout << "\n";
    for (int a = 0; a < 3; a++)
        cout << data[a] << "\n";
}