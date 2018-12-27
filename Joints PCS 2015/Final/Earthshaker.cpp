#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int x2, int y2)
{
    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    return (x * x) + (y * y);
}

int main()
{
    string aghanim;
    bool agha = false;
    int x1, y1, p[5], q[5], h[5], creeps, x[110], y[110];

    cin >> x1 >> y1;

    for (int a = 0; a < 5; a++)
        cin >> p[a] >> q[a] >> h[a];

    cin >> creeps;

    for (int a = 0; a < creeps; a++)
        cin >> x[a] >> y[a];

    cin >> aghanim;

    if (aghanim == "YA")
        agha = true;

    int hero = 0, unit = 0, distperhero[5];

    for (int a = 0; a < 5; a++) {
        distperhero[a] = dist(p[a], q[a], x1, y1);

        if (distperhero[a] <= 25)
            hero++;
    }

    unit = hero;

    for (int a = 0; a < creeps; a++)
        if (dist(x[a], y[a], x1, y1) <= 25)
            unit++;

    int dmg, kill = 0;

    for (int a = 0; a < 5; a++) {
        dmg = 270;
        dmg += (agha ? 140 * unit : 70 * unit);

        if (distperhero[a] <= 25) {
            if (distperhero[a] <= 9)
                dmg += 150;

            dmg = dmg * 3 / 4;

            if (h[a] <= dmg)
                kill++;
        }
    }

    switch (kill) {
    case 0:
        cout << "NOOB\n";
        break;
    case 1:
        cout << "NOT BAD\n";
        break;
    case 2:
        cout << "DOUBLE KILL\n";
        break;
    case 3:
        cout << "TRIPLE KILL\n";
        break;
    case 4:
        cout << "ULTRA KILL\n";
        break;
    case 5:
        cout << "RAMPAGE\n";
        break;
    }
}