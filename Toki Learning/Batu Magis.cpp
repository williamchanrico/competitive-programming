#include <bits/stdc++.h>
using namespace std;

int N, tmp, power[100010];
priority_queue<int> pq;

int main()
{
    cin >> N;
    for (int a = 0; a < N; a++) {
        cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while (N > 0) {
        N--;
        ans++;
        N -= pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}