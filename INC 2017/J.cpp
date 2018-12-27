#include <bits/stdc++.h>
using namespace std;

string inp;

bool process(string x)
{
    for (char a = 'a'; a <= 'z'; a++) {
        string u = x + string(1, a);

        if (inp.find(u) == string::npos) {
            cout << u << "\n";

            return true;
        }

        if (process(u))
            return true;
    }
}

int main()
{
    cin >> inp;

    process("");
}