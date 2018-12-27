#include <bits/stdc++.h>
using namespace std;

int main()
{
    char dummy[20];
    int num, period, K;
    vector<pair<int, int>> v;

    while (scanf("%s", dummy), dummy[0] != '#') {
        scanf("%d %d", &num, &period);

        v.push_back(make_pair(num, period));
    }

    scanf("%d", &K);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int a = 0; a < v.size(); a++) {
        for (int b = 1; b <= K; b++)
            pq.push(make_pair(v[a].second * b, v[a].first));
    }

    for (int a = 0; a < K; a++) {
        printf("%d\n", pq.top().second);

        pq.pop();
    }
}
