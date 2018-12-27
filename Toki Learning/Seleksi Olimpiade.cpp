#include <bits/stdc++.h>
using namespace std;

struct Data {
    char id[10];
    int n[5];
};

bool cmp(const Data& x, const Data& y)
{
    if (x.n[2] == y.n[2])
        if (x.n[1] == y.n[1])
            return x.n[0] > y.n[0];
        else
            return x.n[1] > y.n[1];
    else
        return x.n[2] > y.n[2];
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        int N, M;
        char targetId[10];

        scanf("%d %d %s", &N, &M, targetId);

        vector<Data> v(N);

        for (int a = 0; a < N; a++)
            scanf("%s %d %d %d", v[a].id, &v[a].n[0], &v[a].n[1], &v[a].n[2]);

        sort(v.begin(), v.end(), cmp);

        bool ans = false;

        for (int a = 0; a < M; a++)
            if (strcmp(v[a].id, targetId) == 0)
                ans = true;

        printf("%s\n", (ans ? "YA" : "TIDAK"));
    }
}