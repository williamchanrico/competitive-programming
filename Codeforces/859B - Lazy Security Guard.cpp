#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    scanf("%d", &N);

    int delta, sqRoot = sqrt(N);

    delta = (N - (sqRoot * sqRoot));

    if (delta == 0)
        printf("%d\n", (2 * sqRoot) + (2 * sqRoot));
    else if (delta > sqRoot)
        printf("%d\n", (2 * (sqRoot + 1)) + (2 * (sqRoot + 1)));
    else
        printf("%d\n", (2 * (sqRoot + 1)) + (2 * sqRoot));
}
