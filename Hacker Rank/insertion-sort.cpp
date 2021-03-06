#include <bits/stdc++.h>
using namespace std;

int LSOne(int x)
{
    return (x & (-x));
}

class FenwickTree {
private:
    vector<int> ft;

public:
    FenwickTree(int n) { ft.assign(n + 1, 0); }

    int rsq(int x)
    {
        int sum = 0;
        while (x) {
            sum += ft[x];
            x -= LSOne(x);
        }

        return sum;
    }

    int rsq(int x, int y)
    {
        return rsq(y) - (x == 1 ? 0 : rsq(x - 1));
    }

    void adjust(int k, int v)
    {
        while (k < (int)ft.size()) {
            ft[k] += v;
            k += LSOne(k);
        }
    }
};

int main()
{
    int tc;

    scanf("%d", &tc);
    while (tc--) {
        int N;
        int arr[100001];

        scanf("%d", &N);
        for (int a = 0; a < N; a++) {
            scanf("%d", &arr[a]);
        }

        long long ans = 0;
        FenwickTree ft(1e7 + 1);
        for (int a = N - 1; a >= 0; a--) {
            ft.adjust(arr[a], 1);
            ans += ft.rsq(arr[a] - 1);
        }

        printf("%lld\n", ans);
    }
}
