#include <bits/stdc++.h>
using namespace std;

int main()
{
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);
    A *= 2;
    B *= 3;
    C *= 5;
    printf("MEDIA = %.1lf\n", (A + B + C) / 10.0);
}