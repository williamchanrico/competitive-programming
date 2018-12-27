#include <bits/stdc++.h>
using namespace std;

struct DB {
    int x1, y1, x2, y2;
};

int n, adjMat[2100][2100];
vector<DB> v;

void dfs(int x, int y, int z)
{
    if (x > 0 && x <= 2000 && y > 0 && y <= 2000 && adjMat[x][y] == n) {
        adjMat[x][y] = -1;
        dfs(x + 1, y, z);
        dfs(x, y + 1, z);
        dfs(x - 1, y, z);
        dfs(x, y - 1, z);
    }
}

int main()
{
    cin >> n;
    for (int a = 0; a < n; a++) {
        DB databaru;
        int x, y, p, q;

        cin >> x >> y >> p >> q;

        databaru.x1 = x;
        databaru.x2 = p;
        databaru.y1 = y;
        databaru.y2 = q;

        v.push_back(databaru);
    }

    memset(adjMat, 0, sizeof(adjMat));

    for (int a = 0; a < n; a++) {
        for (int b = v[a].x1; b <= v[a].x2; b++)
            for (int c = v[a].y1; c >= v[a].y2; c--)
                adjMat[b][c]++;
    }

    cin >> n;

    int ans = 0;

    for (int a = 1; a <= 2000; a++)
        for (int b = 1; b <= 2000; b++) {
            if (adjMat[a][b] == n) {
                ans++;
                dfs(a, b, n);
            }
        }

    cout << ans << "\n";
}