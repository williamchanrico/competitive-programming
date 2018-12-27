#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    while (scanf("%d", &N), N) {
        int L, A, B;
        vector<vector<int>> adjList(N);

        scanf("%d", &L);

        for (int a = 0; a < L; a++) {
            scanf("%d %d", &A, &B);

            adjList[A].push_back(B);
            adjList[B].push_back(A);
        }

        bool ans = true;
        vector<int> color(N, -1);
        queue<int> q;

        q.push(0);
        color[0] = 1;

        while (!q.empty()) {
            int front = q.front();

            q.pop();

            for (int a = 0; a < adjList[front].size(); a++) {
                int next = adjList[front][a];

                if (color[next] == -1) {
                    color[next] = 1 - color[front];

                    q.push(next);
                } else if (color[next] == color[front]) {
                    ans = false;

                    break;
                }
            }
        }

        printf("%s\n", (ans ? "BICOLORABLE." : "NOT BICOLORABLE."));
    }
}
