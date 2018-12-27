#include <bits/stdc++.h>
using namespace std;

class Elephant {
public:
    int W, IQ, num;

    bool operator<(const Elephant& x)
    {
        if (this->W == x.W)
            return this->IQ < x.IQ;
        return this->W < x.W;
    }
};

int main()
{
    int count = 1;
    Elephant inp;
    vector<Elephant> v;

    while (scanf("%d %d", &inp.W, &inp.IQ) != EOF) {
        inp.num = count++;

        v.push_back(inp);
    }

    sort(v.begin(), v.end());

    int ans = -1, ansIdx = -1, memo[1100], after[1100];

    for (int a = v.size() - 1; a >= 0; a--) {
        memo[a] = 1;
        after[a] = -1;

        for (int b = a + 1, len = v.size(); b < len; b++) {
            if (v[b].IQ < v[a].IQ && memo[b] + 1 > memo[a]) {
                memo[a] = memo[b] + 1;
                after[a] = b;
            }
        }

        if (memo[a] > ans) {
            ans = memo[a];
            ansIdx = a;
        }
    }

    printf("%d\n", ans);

    while (ansIdx != -1) {
        printf("%d\n", v[ansIdx].num);

        ansIdx = after[ansIdx];
    }
}
