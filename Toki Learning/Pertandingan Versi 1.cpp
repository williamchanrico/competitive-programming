#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> pq;
long long N, T, B, tmp, lawan[100010];

bool cmp(long long x, long long y)
{
    return x > y;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> N;
        for (long long a = 0; a < N; a++)
            cin >> lawan[a];
        for (long long a = 0; a < N; a++) {
            cin >> tmp;
            pq.push(tmp);
        }
        sort(lawan, lawan + N, cmp);
        int ans = 0;
        for (long long a = 0; a < N; a++) {
            if (pq.top() > lawan[a]) {
                pq.pop();
                ans++;
            }
        }
        if (ans > (N - ans))
            cout << "YA\n";
        else
            cout << "TIDAK\n";
    }
}