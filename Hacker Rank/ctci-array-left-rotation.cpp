#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int N, D;
    int arr[100010];

    scanf("%d %d", &N, &D);
    for (int a = 0; a < N; a++)
        scanf("%d", &arr[a]);
    for (int a = 0; a < N; a++) {
        if (a)
            printf(" ");
        printf("%d", arr[(a + D) % N]);
    }
    printf("\n");
}
