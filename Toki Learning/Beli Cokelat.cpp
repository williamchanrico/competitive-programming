#include <bits/stdc++.h>
using namespace std;

long long type, money, p, n, ans = 0;
vector<pair<long long, long long>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> type >> money;
    for (long long a = 0; a < type; a++) {
        cin >> p >> n;
        v.push_back(make_pair(p, n));
    }
    sort(v.begin(), v.end());
    long long idx = 0, sz = v.size(), m = 0;
    while (idx < sz) {
        while (m + v[idx].first <= money && v[idx].second > 0) {
            if (v[idx].second <= (money - m) / v[idx].first) {
                m += (v[idx].first * v[idx].second);
                ans += v[idx].second;
                v[idx].second = 0;
            } else {
                v[idx].second--;
                m += v[idx].first;
                ans++;
            }
        }
        idx++;
    }
    cout << ans << "\n";
}