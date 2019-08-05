#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;

    cin >> A >> B;

    map<char, int> m;
    for (int a = 0, len = A.size(); a < len; a++)
        m[A[a]]++;
    for (int a = 0, len = B.size(); a < len; a++)
        m[B[a]]--;

    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        ans += abs(it->second - 0);
    }
    printf("%d\n", ans);
}
