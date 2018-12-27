#include <bits/stdc++.h>
using namespace std;

int R, C, table[150][150], id[130];
queue<string> inp;

void quadtree(int x, int y, int xx, int yy, string kode)
{
    if (inp.empty())
        return;
    if (kode == inp.front()) {
        for (int a = x; a < xx; a++)
            for (int b = y; b < yy; b++)
                table[a][b] = 1;
        inp.pop();
        return;
    }
    if ((xx > x + 1) && (yy > y + 1)) {
        int mx = (x + xx) / 2, my = (y + yy) / 2;
        quadtree(x, y, mx, my, kode + "0");
        quadtree(x, my, mx, yy, kode + "1");
        quadtree(mx, y, xx, my, kode + "2");
        quadtree(mx, my, xx, yy, kode + "3");
    }
}

int main()
{
    memset(table, 0, sizeof(table));
    int tmp = 2;
    for (int a = 2; a <= 128; a++) {
        if (a > tmp)
            tmp *= 2;
        id[a] = tmp;
    }
    string temp;
    cin >> temp;
    while (temp != "END") {
        inp.push(temp);
        cin >> temp;
    }
    cin >> R >> C;
    quadtree(0, 0, id[R], id[C], "1");
    for (int a = 0; a < R; a++)
        for (int b = 0; b < C; b++)
            if (b == C - 1)
                cout << table[a][b] << "\n";
            else
                cout << table[a][b] << " ";
}