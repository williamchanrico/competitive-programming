#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int N, T;

int main()
{
    scanf("%d %d", &N, &T);
    int temp;
    for (int a = 0; a < N; a++) {
        scanf("%d", &temp);
        if (m.count(temp))
            m[temp]++;
        else
            m[temp] = 1;
    }
    for (int a = 0; a < T; a++) {
        bool ada = false;
        scanf("%d", &temp);
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            int asdf = temp - (it->first);
            if (asdf > 0 && (m.count(asdf))) {
                if (asdf == it->first) {
                    if (m[asdf] >= 2) {
                        ada = true;
                        break;
                    }
                } else {
                    ada = true;
                    break;
                }
            }
        }
        if (ada)
            cout << "YA\n";
        else
            cout << "TIDAK\n";
    }
}