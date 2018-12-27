#include <bits/stdc++.h>
using namespace std;

#define INF 10001

int n, inp, bombed = 0, SIZE;
vector<pair<int, int>> v;
vector<int> ori, ans;

void bomb(int x)
{
    int idx = x + 1, last;
    last = ori[x];
    while (idx < SIZE) {
        if (ori[idx] < last && idx < SIZE) {
            last = ori[idx];
            ori[idx] = INF;
            bombed++;
            idx++;
        } else {
            break;
        }
    }
    last = ori[x];
    ori[x] = INF;
    idx = x - 1;
    bombed++;
    while (idx > -1) {
        if (ori[idx] < last && idx > -1) {
            last = ori[idx];
            ori[idx] = INF;
            bombed++;
            idx--;
        } else {
            break;
        }
    }
}

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.first == y.first)
        return x.second < y.second;
    return x.first > y.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int a = 1; a <= n; a++) {
        cin >> inp;
        v.push_back(make_pair(inp, a));
        ori.push_back(inp);
    }
    sort(v.begin(), v.end(), cmp);
    SIZE = v.size();
    int idx = 0;
    while (bombed < SIZE) {
        if (ori[v[idx].second - 1] != INF) {
            ans.push_back(v[idx].second);
            bomb(v[idx].second - 1);
        }
        idx++;
    }
    sort(ans.begin(), ans.end());
    for (int a = 0, sz = ans.size(); a < sz; a++)
        cout << ans[a] << "\n";
}