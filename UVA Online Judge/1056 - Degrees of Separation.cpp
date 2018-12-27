#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

map<string, int> m;
int AdjMat[60][60];
int nameIdx = 0;

int idxOf(string name)
{
    if (m.count(name) != 0)
        return m[name];
    return m[name] = nameIdx++;
}

void reset()
{
    nameIdx = 0;
    m.clear();

    for (int a = 0; a < 60; a++)
        for (int b = 0; b < 60; b++)
            AdjMat[a][b] = INF;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int P, R, counter = 0;

    while (cin >> P >> R, (P || R)) {
        int maxDist = -INF;

        reset();

        for (int a = 0; a < R; a++) {
            string inp1, inp2;

            cin >> inp1 >> inp2;

            AdjMat[idxOf(inp1)][idxOf(inp2)] = 1;
            AdjMat[idxOf(inp2)][idxOf(inp1)] = 1;
        }

        for (int a = 0; a < P; a++)
            for (int b = 0; b < P; b++)
                for (int c = 0; c < P; c++)
                    AdjMat[b][c] = min(AdjMat[b][c], AdjMat[b][a] + AdjMat[a][c]);

        bool valid = true;

        for (int a = 0; a < P && valid; a++) {
            for (int b = 0; b < P; b++) {
                maxDist = max(maxDist, (a != b ? AdjMat[a][b] : -INF));
                if (AdjMat[a][b] == INF && a != b)
                    valid = false;
            }
        }

        cout << "Network " << ++counter << ": ";

        if (valid)
            cout << maxDist << "\n\n";
        else
            cout << "DISCONNECTED\n\n";
    }
}