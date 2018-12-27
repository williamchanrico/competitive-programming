#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    double C;
    scanf("%d %d %lf", &A, &B, &C);
    C *= B;
    printf("NUMBER = %d\n", A);
    printf("SALARY = U$ %.2lf\n", C);
}