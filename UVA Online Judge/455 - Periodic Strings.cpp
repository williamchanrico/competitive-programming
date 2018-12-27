#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1100000

string str, strP;
int backTable[MAX_N];

void kmpPreprocess()
{
    int a = 0, b = -1;

    backTable[0] = -1;

    while (a < strP.size()) {
        while (b >= 0 && strP[a] != strP[b])
            b = backTable[b];

        a++;
        b++;

        backTable[a] = b;
    }
}

int kmpSearch()
{
    int a = 0, b = 0, ans = 0;

    while (a < str.size()) {
        while (b >= 0 && str[a] != strP[b])
            b = backTable[b];

        a++;
        b++;

        if (b == strP.size()) {
            ans++;

            b = backTable[b];
        }
    }

    return ans;
}

int main()
{
    int N;

    cin >> N;

    while (N--) {
        cin >> strP;

        str = strP + strP;

        kmpPreprocess();

        cout << ((str.size() / 2.0) / (kmpSearch() - 1)) << "\n";

        if (N)
            cout << "\n";
    }
}