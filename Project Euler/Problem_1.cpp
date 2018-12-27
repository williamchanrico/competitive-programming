#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;

    for (int a = 0; a < 1000; a++)
        if (a % 3 == 0 || a % 5 == 0)
            ans += a;

    cout << ans << "\n";
}