#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

bool valid(string x, string y)
{
    if (x.size() < y.size())
        swap(x, y);

    return !(x.substr(0, y.size()) == y);
}

int main()
{
    int TC = 1;
    string str[15];

    while (cin >> str[0]) {
        bool ans = true;

        for (int a = 1; str[a - 1] != "9"; a++) {
            cin >> str[a];

            for (int b = 0; b < a; b++)
                if (!valid(str[a], str[b]))
                    ans = false;
        }

        printf("Set %d is %simmediately decodable\n", TC++, (ans ? "" : "not "));
    }
}
