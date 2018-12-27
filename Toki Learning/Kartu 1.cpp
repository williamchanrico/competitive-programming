#include <bits/stdc++.h>
using namespace std;

string inp;
int A = 0, B = 0;

int main()
{
    for (int a = 0; a < 6; a++) {
        cin >> inp;
        if (inp[1] == 'B')
            B++;
        else
            A++;
    }
    if (B >= 3)
        cout << "100\n";
    else if (B >= 2)
        cout << "70\n";
    else if (A > 0 && B > 0)
        cout << "40\n";
    else if (A >= 2 && B > 0)
        cout << "25\n";
    else if (A >= 3)
        cout << "20\n";
}
