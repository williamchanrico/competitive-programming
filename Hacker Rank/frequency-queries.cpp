#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;

    scanf("%d", &Q);

    int query, inp;
    map<int, int> m;
    map<int, int> exists;
    while (Q--) {
        scanf("%d %d", &query, &inp);
        switch (query) {
        case 1:
            exists[m[inp]] = max(exists[m[inp]] - 1, 0);
            ++m[inp];
            ++exists[m[inp]];
            break;
        case 2:
            exists[m[inp]] = max(exists[m[inp]] - 1, 0);
            m[inp] = max(m[inp] - 1, 0);
            ++exists[m[inp]];
            break;
        case 3:
            printf("%d\n", (exists[inp] ? 1 : 0));
            break;
        }
    }
}
