#include <bits/stdc++.h>
using namespace std;

float get_median(const vector<int>& count, int size)
{
    int mid = size / 2;
    if (size % 2 == 1) {
        ++mid;
    }

    int sum = 0;
    float median = -1.0;
    for (int a = 0; a <= 200; a++) {
        sum += count[a];

        if (sum >= mid) {
            if (median == -1.0) {
                median = a;
            }

            if (size % 2 == 1) {
                break;
            }

            if (sum == mid) {
                continue;
            }

            median = (median + a) / 2.0;
            break;
        }
    }

    return median;
}

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);

    int ans = 0;
    vector<int> v(N + 1);
    vector<int> count(201, 0);
    for (int a = 1; a <= N; a++) {
        scanf("%d", &v[a]);

        if (a > D) {
            float median = get_median(count, D);
            if (2.0 * median <= v[a]) {
                ++ans;
            }

            --count[v[a - D]];
            assert(v[a - D] >= 0);
        }
        ++count[v[a]];
    }

    printf("%d\n", ans);
}
