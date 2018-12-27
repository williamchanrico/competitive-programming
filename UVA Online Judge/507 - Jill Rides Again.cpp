#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int main()
{
    int T;

    scanf("%d", &T);

    for (int TC = 1; TC <= T; TC++) {
        int N;
        int sum = 0;
        int maxSum = -INF;
        int start = 0;
        int end = 0;
        int tempStart = 0;

        scanf("%d", &N);

        for (int a = 0; a < (N - 1); a++) {
            int inp;

            scanf("%d", &inp);

            sum += inp;

            if (maxSum < sum) {
                maxSum = sum;
                start = tempStart;
                end = a;
            } else if (maxSum == sum && ((a - tempStart) > (end - start))) {
                start = tempStart;
                end = a;
            }

            if (sum < 0) {
                sum = 0;
                tempStart = a + 1;
            }
        }

        if (maxSum > 0) {
            printf("The nicest part of route %d is between stops %d and %d\n", TC, start + 1, end + 2);
        } else {
            printf("Route %d has no nice parts\n", TC);
        }
    }
}