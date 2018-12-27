#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000
#define EPS 1e-9

int N, X[20], Y[20], target;
double dist[20][20], memo[1 << 16];

double hypot(double x, double y)
{
    return sqrt(x * x + y * y);
}

double dp(int bitmask)
{
    if (bitmask == target)
        return memo[bitmask] = 0;
    if (memo[bitmask] != -1.0)
        return memo[bitmask];

    int p1, p2;

    for (p1 = 0; p1 < (2 * N); p1++)
        if (!(bitmask & (1 << p1)))
            break;

    double ans = INF;

    for (p2 = p1 + 1; p2 < (2 * N); p2++)
        if (!(bitmask & (1 << p2)))
            ans = min(ans, dist[p1][p2] + dp(bitmask | (1 << p1) | (1 << p2)));

    return memo[bitmask] = ans;
}

int main()
{
    int T = 1;

    while (scanf("%d", &N) && N) {
        for (int a = 0; a < (2 * N); a++)
            scanf("%*s %d %d", &X[a], &Y[a]);

        for (int a = 0; a < (2 * N); a++)
            for (int b = 0; b < (2 * N); b++)
                dist[a][b] = dist[b][a] = hypot(X[b] - X[a], Y[b] - Y[a]);

        for (int a = 0; a < (1 << 16); a++)
            memo[a] = -1.0;

        target = (1 << (2 * N)) - 1;

        printf("Case %d: %.2lf\n", T++, dp(0));
    }
}