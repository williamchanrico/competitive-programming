#include <stdio.h>
#include <stdlib.h>

int main()
{
    bool tx, ty;
    int x, y, temp;

    scanf("%d%d", &x, &y);
    if (x < 0)
        tx = false;
    else
        tx = true;
    if (y < 0)
        ty = false;
    else
        ty = true;
    if (tx == true && ty == true) {
        temp = x + y;
        printf("0 %d %d 0\n", temp, temp);
    } else if (tx == false && ty == true) {
        temp = abs(x) + abs(y);
        printf("-%d 0 0 %d\n", temp, temp);
    } else if (tx == true && ty == false) {
        temp = abs(x) + abs(y);
        printf("0 -%d %d 0\n", temp, temp);
    } else if (tx == false && ty == false) {
        temp = abs(x) + abs(y);
        printf("-%d 0 0 -%d\n", temp, temp);
    }
}