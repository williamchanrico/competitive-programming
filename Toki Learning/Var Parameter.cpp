#include <stdio.h>

int A, B;

void tukar(int& A, int& B)
{
    A = A + B;
    B = A - B;
    A = A - B;
}

int main()
{
    scanf("%d %d", &A, &B);
    tukar(A, B);
    printf("%d %d\n", A, B);
}
