#include <bits/stdc++.h>
using namespace std;

int n, grid[20][20];

int main()
{
    cin >> n;
    for (int a = 0, b = 1, c = 2; a < n; a++, c++) {
        grid[a][0] = b;
        grid[0][a] = b;
        b += c;
    }
    for (int a = 1; a < n; a++)
        for (int b = 1; b < n; b++)
            grid[a][b] = grid[a - 1][b] + grid[a][b - 1];
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++)
            if (b == 0)
                cout << grid[a][b];
            else
                cout << " " << grid[a][b];
        cout << "\n";
    }
}
