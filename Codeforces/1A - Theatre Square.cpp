#include <math.h>
#include <stdio.h>

int main()
{
    double x, y, z;

    scanf("%lf %lf %lf", &x, &y, &z);
    x = ceil(x / z);
    y = ceil(y / z);
    printf("%.0lf", x * y);
}