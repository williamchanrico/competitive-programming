#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        auto N = 0;
        auto money = 0;

        scanf("%d %d", &money, &N);

        map<int, vector<int>> m;
        for (int a = 1; a <= N; a++) {
            int inp;
            scanf("%d", &inp);
            m[inp].push_back(a);
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            auto& potential_price1 = it->first;

            auto potential_price2 = money - it->first;
            if (m.count(potential_price2)) {
                vector<int> indexes1 = m[potential_price1];
                vector<int> indexes2 = m[potential_price2];

                int ans1, ans2;
                if (potential_price1 == potential_price2) {
                    ans1 = indexes1[0];
                    ans2 = indexes1[1];
                } else {
                    ans1 = indexes1[0];
                    ans2 = indexes2[0];
                }

                if (ans1 > ans2)
                    swap(ans1, ans2);

                printf("%d %d\n", ans1, ans2);
                break;
            }
        }
    }
}
