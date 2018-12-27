#include <bits/stdc++.h>
using namespace std;

map<int, bool> m;
int N, inp;

int main()
{
    scanf("%d\n", &N);
    for (int a = 0; a < N - 2; a++) {
        scanf("%d", &inp);
        m[inp] = 1;
    }
    for (int a = 1; a <= N; a++)
        if (!m.count(a))
            printf("%d\n", a);
}