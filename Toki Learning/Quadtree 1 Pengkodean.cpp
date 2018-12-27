#include <bits/stdc++.h>
using namespace std;

int R, C, table[150][150], id[130];

void quadtree(int x, int y, int xx, int yy, string kode)
{
    bool satu = false, nol = false;
    for (int a = x; a < xx; a++)
        for (int b = y; b < yy; b++)
            if (table[a][b] == 0)
                nol = true;
            else
                satu = true;
    if (satu && nol) {
        int mx = (x + xx) / 2, my = (y + yy) / 2;
        quadtree(x, y, mx, my, kode + "0");
        quadtree(x, my, mx, yy, kode + "1");
        quadtree(mx, y, xx, my, kode + "2");
        quadtree(mx, my, xx, yy, kode + "3");
    } else if (satu) {
        cout << "1" << kode << "\n";
    }
}

int main()
{
    scanf("%d %d", &R, &C);
    int tmp = 2;
    for (int a = 2; a <= 128; a++) {
        if (a > tmp)
            tmp *= 2;
        id[a] = tmp;
    }
    memset(table, 0, sizeof(table));
    for (int a = 0; a < R; a++)
        for (int b = 0; b < C; b++)
            scanf("%d", &table[a][b]);
    quadtree(0, 0, id[R], id[C], "");
    cout << "END\n";
}