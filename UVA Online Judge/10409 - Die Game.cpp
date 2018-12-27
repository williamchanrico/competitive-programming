#include <iostream>
using namespace std;

int n;
int T = 1, N = 2, W = 3, E = 4, S = 5, B = 6;

void flip(string x)
{
    int temp;
    if (x == "north") {
        temp = N;
        N = T;
        T = S;
        S = B;
        B = temp;
    } else if (x == "south") {
        temp = S;
        S = T;
        T = N;
        N = B;
        B = temp;
    } else if (x == "east") {
        temp = E;
        E = T;
        T = W;
        W = B;
        B = temp;
    } else if (x == "west") {
        temp = W;
        W = T;
        T = E;
        E = B;
        B = temp;
    }
}

int main()
{
    string inp;
    while (cin >> n, n) {
        for (int a = 0; a < n; a++) {
            cin >> inp;
            flip(inp);
        }
        cout << T << endl;
        T = 1, N = 2, W = 3, E = 4, S = 5, B = 6;
    }
}