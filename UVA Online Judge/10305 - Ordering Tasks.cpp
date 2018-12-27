#include <bits/stdc++.h>
using namespace std;

bitset<110> bs;
vector<int> ans;
vector<vector<int>> adjList;

void dfs(int x)
{
    if (bs[x]) {
        bs[x] = false;

        for_each(adjList[x].begin(), adjList[x].end(), dfs);

        ans.push_back(x);
    }
}

int main()
{
    int N, M;

    while (scanf("%d %d", &N, &M), (N | M)) {
        int A, B;

        bs.set();
        adjList.assign(N + 1, vector<int>());
        ans.clear();

        for (int a = 0; a < M; a++) {
            scanf("%d %d", &A, &B);

            adjList[A].push_back(B);
        }

        for (int a = 1; a <= N; a++)
            if (bs[a])
                dfs(a);

        for (int a = ans.size() - 1; a >= 0; a--)
            if (a)
                printf("%d ", ans[a]);
            else
                printf("%d", ans[a]);
        printf("\n");
    }
}
