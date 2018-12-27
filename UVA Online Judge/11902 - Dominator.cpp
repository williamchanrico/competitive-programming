#include <bits/stdc++.h>
using namespace std;

int N;
char ans[110][110];
bitset<110> visitA, visitB;
vector<vector<int>> adjList;

void dfs(int x, int block)
{
    if (block == -1) {
        if (!visitA[x])
            return;

        visitA[x] = 0;

    } else {
        if (!visitB[x] || x == block)
            return;

        visitB[x] = 0;
    }

    for (int a = 0; a < adjList[x].size(); a++)
        dfs(adjList[x][a], block);
}

void printAns()
{
    for (int a = 0; a < N; a++) {

        printf("+");

        for (int b = 0; b < (2 * N - 1); b++)
            printf("-");

        printf("+\n|");

        for (int b = 0; b < N; b++)
            printf("%c|", ans[a][b]);

        printf("\n");
    }

    printf("+");

    for (int a = 0; a < (2 * N - 1); a++)
        printf("-");

    printf("+\n");
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int TC = 1; TC <= T; TC++) {
        int inp;

        scanf("%d", &N);

        adjList.assign(N, vector<int>());

        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                scanf("%d", &inp);

                if (inp)
                    adjList[a].push_back(b);
            }
        }

        visitA.set();

        dfs(0, -1);

        for (int a = 0; a < N; a++) {
            visitB.set();

            dfs(0, a);

            for (int b = 0; b < N; b++) {
                if (visitA[b])
                    ans[a][b] = 'N';
                else if (visitB[b])
                    ans[a][b] = 'Y';
                else
                    ans[a][b] = 'N';
            }
        }

        printf("Case %d:\n", TC);

        printAns();
    }
}
