#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

vector<int> v, tail(100000, INF);
int memo[100000], p[100000];

int dp()
{
    int len = 0;

    for (int a = 0; a < v.size(); a++) {
        int left = 1;
        int right = len;

        while (left <= right) {
            int mid = ceil((left + right) / 2.0);

            if (v[tail[mid]] < v[a])
                left = mid + 1;
            else
                right = mid - 1;
        }

        tail[left] = a;
        p[a] = tail[left - 1];

        len += (left > len ? 1 : 0);
    }

    return len;
}

void printDp(int idx, int count)
{
    if (count == 0)
        return;

    printDp(p[idx], count - 1);

    printf("%d\n", v[idx]);
}

int main()
{
    int inp;

    while (scanf("%d", &inp) != EOF)
        v.push_back(inp);

    int ans = dp();

    printf("%d\n-\n", ans);

    printDp(tail[ans], ans);
}