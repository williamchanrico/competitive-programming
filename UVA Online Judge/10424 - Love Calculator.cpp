#include <bits/stdc++.h>
using namespace std;

map<char, int> m;

int work(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    if (ans > 9)
        return work(ans);
    return ans;
}

double love(string x, string y)
{
    int szX = x.size(), szY = y.size();
    int X = 0, Y = 0;
    for (int a = 0; a < szX; a++)
        X += m[x[a]];
    X = work(X);
    for (int a = 0; a < szY; a++)
        Y += m[y[a]];
    Y = work(Y);
    return X < Y ? (X * 100.0) / Y : (Y * 100.0) / X;
}

int main()
{
    int counter = 1;
    for (char a = 'a'; a <= 'z'; a++, counter++)
        m[a] = counter;
    counter = 1;
    for (char a = 'A'; a <= 'Z'; a++, counter++)
        m[a] = counter;
    string str, inp;
    int idx = 0;
    while (getline(cin, inp)) {
        if (idx == 1) {
            printf("%.2lf %c\n", love(str, inp), '%');
            idx = 0;
        } else {
            str = inp;
            idx++;
        }
    }
}
