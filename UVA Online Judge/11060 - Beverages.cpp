#include <bits/stdc++.h>
using namespace std;

int main()
{
    int TC = 1, N, M;

    while (cin >> N) {
        string A, B;
        map<string, int> mIdx;
        map<int, string> mStr;

        for (int a = 0; a < N; a++) {
            cin >> A;

            mIdx[A] = a;
            mStr[a] = A;
        }

        cin >> M;

        vector<vector<int>> adjList(N);
        vector<int> inDegree(N, 0);

        for (int a = 0; a < M; a++) {
            cin >> A >> B;

            adjList[mIdx[A]].push_back(mIdx[B]);
            inDegree[mIdx[B]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int a = 0; a < N; a++)
            if (!inDegree[a])
                pq.push(a);

        cout << "Case #" << TC++ << ": Dilbert should drink beverages in this order:";

        while (!pq.empty()) {
            int front = pq.top();

            pq.pop();

            cout << " " << mStr[front];

            for (int a = 0; a < adjList[front].size(); a++) {
                inDegree[adjList[front][a]]--;

                if (inDegree[adjList[front][a]] == 0)
                    pq.push(adjList[front][a]);
            }
        }

        cout << ".\n\n";
    }
}
