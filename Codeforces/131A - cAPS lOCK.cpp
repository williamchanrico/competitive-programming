#include <iostream>
using namespace std;

bool alluppercase(string x)
{
    for (int a = 0, sz = x.size(); a < sz; a++)
        if ((int)x[a] <= 122 && (int)x[a] >= 97)
            return false;
    return true;
}

bool onlyfrontlowercase(string x)
{
    if ((int)x[0] >= 65 && (int)x[0] <= 90)
        return false;
    else
        for (int a = 1, sz = x.size(); a < sz; a++)
            if ((int)x[a] >= 97 && (int)x[a] <= 122)
                return false;
    return true;
}

bool isUpper(char x)
{
    if ((int)x >= 65 && (int)x <= 90)
        return true;
    return false;
}

int main()
{
    string inp;
    cin >> inp;
    if (!alluppercase(inp) && !onlyfrontlowercase(inp)) {
        cout << inp << "\n";
    } else {
        for (int a = 0, sz = inp.size(); a < sz; a++)
            if (isUpper(inp[a]))
                cout << (char)tolower(inp[a]);
            else
                cout << (char)toupper(inp[a]);
        cout << "\n";
    }
}
