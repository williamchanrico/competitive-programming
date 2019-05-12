#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int a = 0; a < n; a++) {
        for (int b = n - a - 1; b > 0; b--)
            printf(" ");
        for (int b = 0 - 1; b < a; b++)
            printf("#");
        printf("\n");
    }
}
