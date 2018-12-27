#include <bits/stdc++.h>
using namespace std;

int arr[] = { 2, 3, 4, 5, 6, 7 };

bool tes()
{
    int x = arr[0];
    int y = (10 * arr[1]) + arr[2];
    int z = x * y;

    int lol = z, temp[3];
    for (int a = 2; a > -1; a--) {
        temp[a] = lol % 10;
        lol /= 10;
    }
    if (temp[0] == arr[3] && temp[1] == arr[4] && temp[2] == arr[5]) {
        cout << x << "*" << y << "=" << z << "\n";
        return true;
    }
    return false;
}

int main()
{
    do {
        tes();
    } while (next_permutation(arr, arr + 6));
}