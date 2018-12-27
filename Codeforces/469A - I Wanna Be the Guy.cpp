#include <bits/stdc++.h>
using namespace std;

map<int, bool> m;

int main()
{
    int n, inp, temp, ans = 0;
    scanf("%d", &n);
    scanf("%d", &temp);
    while (temp--) {
        scanf("%d", &inp);
        ans += !m.count(inp);
        m[inp] = true;
    }
    scanf("%d", &temp);
    while (temp--) {
        scanf("%d", &inp);
        ans += !m.count(inp);
        m[inp] = true;
    }
    printf("%s\n", (ans == n) ? "I become the guy." : "Oh, my keyboard!");
}