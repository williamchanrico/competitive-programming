// Fors

#include <bits/stdc++.h>
using namespace std;

int f(int x, int y, int op)
{
    switch (op) {
    case 0:
        return x * y;
        break;
    case 1:
        return x + y;
        break;
    case 2:
        return x - y;
        break;
    }
}

int main()
{
    int N, arr[4], ans = 0;

    cin >> N >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                do {
                    if (f(f(f(arr[0], arr[1], a), arr[2], b), arr[3], c) == N)
                        ans++;
                } while (next_permutation(arr, arr + 4));

    cout << ans << "\n";
}