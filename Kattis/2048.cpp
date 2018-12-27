#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int dir, arr[20][20];

void rotateLeft(int count)
{
    while (count--) {
        for (int a = 0; a < N; a++)
            for (int b = a; b < N; b++)
                swap(arr[a][b], arr[b][a]);

        for (int a = 0; a < (N / 2); a++)
            for (int b = 0; b < N; b++)
                swap(arr[a][b], arr[N - a - 1][b]);
    }
}

void fillLeft(int row)
{
    for (int a = 0; a < N; a++) {
        for (int b = N - 1; b > 0; b--) {
            if (arr[row][b - 1] == 0) {
                arr[row][b - 1] = arr[row][b];
                arr[row][b] = 0;
            }
        }
    }
}

void slideLeft()
{
    for (int a = 0; a < N; a++) {

        fillLeft(a);

        for (int b = 1; b < N; b++) {
            if (arr[a][b] == arr[a][b - 1]) {
                arr[a][b - 1] *= 2;
                arr[a][b] = 0;

                fillLeft(a);
            }
        }
    }
}

int main()
{
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++)
            scanf("%d", &arr[a][b]);

    scanf("%d", &dir);

    rotateLeft(dir);

    slideLeft();

    rotateLeft((N - dir) % N);

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++)
            printf("%d ", arr[a][b]);

        printf("\n");
    }
}
