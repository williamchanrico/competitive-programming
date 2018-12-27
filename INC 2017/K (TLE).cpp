#include <bits/stdc++.h>
using namespace std;

int N, B[110];
map<string, bool> memo;

bool allZero()
{
    for (int a = 0; a < N; a++)
        if (B[a] != 0)
            return false;
    return true;
}

string toString()
{
    string ret = "";

    for (int a = 0; a < N; a++)
        ret += B[a];

    return ret;
}

bool backtrack()
{
    string key = toString();

    if (memo.count(key))
        return memo[key];
    if (allZero())
        return true;

    for (int a = 1; a < N; a++) {
        if (B[a - 1] >= 1 && B[a] >= 2) {
            B[a - 1] -= 1;
            B[a] -= 2;

            if (backtrack())
                return memo[key] = true;

            B[a - 1] += 1;
            B[a] += 2;
        }

        if (B[a - 1] >= 2 && B[a] >= 1) {
            B[a - 1] -= 2;
            B[a] -= 1;

            if (backtrack())
                return memo[key] = true;

            B[a - 1] += 2;
            B[a] += 1;
        }
    }

    return memo[key] = false;
}

int main()
{
    scanf("%d", &N);

    for (int a = 0; a < N; a++)
        scanf("%d", &B[a]);

    if (backtrack())
        printf("YES\n");
    else
        printf("NO\n");
}