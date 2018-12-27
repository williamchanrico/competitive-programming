#include <bits/stdc++.h>
using namespace std;

#define MAX_N 110000

string str;
int SA[MAX_N], tempSA[MAX_N];
int RA[MAX_N], tempRA[MAX_N];
int c[MAX_N], phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];

bool cmp(int x, int y) { return (str.substr(x) < str.substr(y)); }

void constructSA1()
{
    for (int a = 0; a < str.size(); a++)
        SA[a] = a;

    sort(SA, SA + str.size(), cmp);
}

void countingSort(int x)
{
    int sum, maxi = max(300, (int)str.size());

    memset(c, 0, sizeof(c));

    for (int a = 0; a < str.size(); a++)
        c[(a + x < str.size() ? RA[a + x] : 0)]++;

    for (int a = sum = 0; a < maxi; a++) {
        int temp = c[a];

        c[a] = sum;
        sum += temp;
    }

    for (int a = 0; a < str.size(); a++)
        tempSA[c[(SA[a] + x < str.size() ? RA[SA[a] + x] : 0)]++] = SA[a];

    for (int a = 0; a < str.size(); a++)
        SA[a] = tempSA[a];
}

void constructSA2()
{
    int rank;

    for (int a = 0; a < str.size(); a++)
        RA[a] = str[a];

    for (int a = 0; a < str.size(); a++)
        SA[a] = a;

    for (int a = 1; a < str.size(); a <<= 1) {
        countingSort(a);
        countingSort(0);

        tempRA[SA[0]] = rank = 0;

        for (int b = 1; b < str.size(); b++)
            tempRA[SA[b]] = ((RA[SA[b]] == RA[SA[b - 1]]) && (RA[SA[b] + a] == RA[SA[b - 1] + a]) ? rank : ++rank);

        for (int b = 0; b < str.size(); b++)
            RA[b] = tempRA[b];

        if (RA[SA[str.size() - 1]] == str.size() - 1)
            break;
    }
}

void computeLCP()
{
    int L;

    phi[SA[0]] = -1;

    for (int a = 1; a < str.size(); a++)
        phi[SA[a]] = SA[a - 1];

    for (int a = L = 0; a < str.size(); a++) {
        if (phi[a] == -1) {
            PLCP[a] = 0;

            continue;
        }

        while (str[a + L] == str[phi[a] + L])
            L++;

        PLCP[a] = L;

        L = max(L - 1, 0);
    }

    for (int a = 0; a < str.size(); a++)
        LCP[a] = PLCP[SA[a]];
}

int main()
{
    cin >> str;

    constructSA2();

    computeLCP();

    for (int a = 0; a < str.size(); a++)
        cout << SA[a] << " " << LCP[a] << " " << str.substr(SA[a]) << "\n";
}