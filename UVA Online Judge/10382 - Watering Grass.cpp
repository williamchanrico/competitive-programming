#include <bits/stdc++.h>
using namespace std;

class Sprinkler {
public:
    double left;
    double right;
};

bool cmp(const Sprinkler& x, const Sprinkler& y)
{
    if (x.left == y.left)
        return x.right > y.right;
    return x.left < y.left;
}

int main()
{
    int N, L, W;

    while (scanf("%d %d %d", &N, &L, &W) != EOF) {
        int X, R;
        Sprinkler sprinkler;
        vector<Sprinkler> v;

        for (int a = 0; a < N; a++) {
            scanf("%d %d", &X, &R);

            if (R * 2 < W)
                continue;

            double dx = sqrt(((double)R * R) - ((W / 2.0) * (W / 2.0)));

            sprinkler.left = X - dx;
            sprinkler.right = X + dx;

            v.push_back(sprinkler);
        }

        sort(v.begin(), v.end(), cmp);

        int ans = 0;
        double reached = 0;

        while (reached < L) {
            double newReached = reached;

            for (int a = 0; a < v.size(); a++) {
                if (v[a].left > reached)
                    break;

                newReached = max(newReached, v[a].right);
            }

            if (reached == newReached)
                break;

            reached = newReached;

            ++ans;
        }

        printf("%d\n", (reached < L ? -1 : ans));
    }
}
