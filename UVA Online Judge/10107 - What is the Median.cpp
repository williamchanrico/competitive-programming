#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int inp;
    while (cin >> inp) {
        v.push_back(inp);
        if (v.size() % 2 == 1) {
            sort(v.begin(), v.end());
            cout << v[v.size() / 2] << "\n";
        } else {
            sort(v.begin(), v.end());
            cout << (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2 << "\n";
        }
    }
}