#include <math.h>
#include <stdio.h>

double N;

int main()
{
    scanf("%lf", &N);
    printf("%.lf %.lf\n", floor(N), ceil(N));
}
