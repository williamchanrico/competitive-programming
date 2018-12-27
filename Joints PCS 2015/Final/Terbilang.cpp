#include <bits/stdc++.h>
using namespace std;

string bil[20] = { "nol", "satu", "dua", "tiga", "empat", "lima",
    "enam", "tujuh", "delapan", "sembilan", "sepuluh",
    "sebelas" };

int stoi(string x)
{
    int n;

    istringstream(x) >> n;

    return n;
}

int main()
{
    int digit;
    bool koma = false;
    string n, ans = "";

    cin >> n;

    for (int a = 0; a < n.size(); a++) {
        if (n[a] == '.')
            koma = true, digit = a;

        if (a == n.size() - 1 && !koma)
            digit = n.size();
    }

    string temp = "";

    switch (digit) {
    case 1:
        temp += n[0];
        ans += bil[stoi(temp)];
        ans[0] -= 32;

        break;
    case 2:
        if (n[0] == '1') {
            temp = "";
            temp += n[1];

            if (n[1] == '0') {
                ans += "Sepuluh";
            } else if (n[1] == '1') {
                ans += "Sebelas";
            } else {
                ans += bil[stoi(temp)] + " belas";
                ans[0] -= 32;
            }

        } else {
            if (n[1] == '0') {
                temp += n[0];
                ans += bil[stoi(temp)] + " puluh";
                ans[0] -= 32;
            } else {
                temp += n[0];
                ans += bil[stoi(temp)] + " puluh";
                ans[0] -= 32;
                temp = "";
                temp += n[1];
                ans += " " + bil[stoi(temp)];
            }
        }

        break;
    }

    if (koma) {
        ans += " koma";

        for (int a = digit + 1; a < n.size(); a++) {
            temp = "";
            temp += n[a];
            ans += " " + bil[stoi(temp)];
        }

        cout << ans << "\n";
    } else {
        cout << ans << "\n";
    }
}