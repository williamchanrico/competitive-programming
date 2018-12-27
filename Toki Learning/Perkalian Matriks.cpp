#include <stdio.h>

int matriks1[105][105], matriks2[105][105], matriks3[105][105];
int A, B, C, D;

int main()
{
    scanf("%d %d", &A, &B);
    for (int a = 0; a < A; a++)
        for (int b = 0; b < B; b++)
            scanf("%d", &matriks1[a][b]);
    scanf("%d %d", &C, &D);
    for (int a = 0; a < C; a++)
        for (int b = 0; b < D; b++)
            scanf("%d", &matriks2[a][b]);
    for (int a = 0; a < A; a++)
        for (int b = 0; b < D; b++) {
            matriks3[a][b] = 0;
            for (int c = 0; c < B; c++)
                matriks3[a][b] += (matriks1[a][c] * matriks2[c][b]);
        }
    for (int a = 0; a < A; a++) {
        for (int b = 0; b < D; b++)
            if (b == 0)
                printf("%d", matriks3[a][b]);
            else
                printf(" %d", matriks3[a][b]);
        printf("\n");
    }
}
