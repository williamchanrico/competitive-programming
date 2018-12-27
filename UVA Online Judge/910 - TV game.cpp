#include <bits/stdc++.h>
using namespace std;

int N, M, adjMatrix[30][2], memo[40][30];
bitset<30> isSpecial;

int dp(int steps, int pos)
{
    if (steps == M)
        return isSpecial[pos];
    if (memo[steps][pos] != -1)
        return memo[steps][pos];

    return memo[steps][pos] = dp(steps + 1, adjMatrix[pos][0]) + dp(steps + 1, adjMatrix[pos][1]);
}

int main()
{
    while (scanf("%d", &N) != EOF) {

        isSpecial.reset();

        for (int a = 0; a < N; a++) {
            char zero, one, type;

            scanf(" %*c %c %c %c", &zero, &one, &type);

            adjMatrix[a][0] = zero - 'A';
            adjMatrix[a][1] = one - 'A';

            if (type == 'x')
                isSpecial[a] = true;
        }

        scanf("%d", &M);

        memset(memo, -1, sizeof(memo));

        printf("%d\n", dp(0, 0));
    }
}