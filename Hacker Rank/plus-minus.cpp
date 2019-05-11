#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    int negative = 0;
    int positive = 0;
    int zero = 0;

    for (int a = 0, inp = 0; a < n; a++) {
        scanf("%d", &inp);
        if (inp < 0)
            ++negative;
        else if (inp > 0)
            ++positive;
        else
            ++zero;
    }

    printf("%.6lf\n%.6lf\n%.6lf\n",
        (double)positive / n, (double)negative / n, (double)zero / n);
}
