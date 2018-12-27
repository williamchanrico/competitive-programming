#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

map<int, int> m;
vector<int> v;
int R, C;
double V;

double hitung(double x)
{
    int filled = 0;
    double vol = 0;
    if (v[0] != 0)
        x -= (double)v[0];
    for (int a = 0, sz = v.size() - 1; a < sz; a++) {
        int height = v[a + 1] - v[a];
        if (height <= x) {
            x -= height;
            vol += (filled + m[v[a]]) * height;
            filled += m[v[a]];
        } else {
            vol += (filled + m[v[a]]) * x;
            x = 0;
            filled += m[v[a]];
        }
    }
    return vol;
}

int main()
{
    cin >> R >> C >> V;
    int inp;
    for (int a = 0; a < R; a++)
        for (int b = 0; b < C; b++) {
            cin >> inp;
            if (!m.count(inp)) {
                m[inp] = 1;
                v.push_back(inp);
            } else {
                m[inp]++;
            }
        }
    v.push_back(INF);
    m[INF] = 1;
    sort(v.begin(), v.end());
    double hi = 1000000, lo = 0, mid, hasil = -1;
    while (fabs(hi - lo) > 0.000001) {
        mid = (hi + lo) / 2;
        if (hitung(mid) < V)
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(3) << (hi + lo) / 2 << "\n";
}