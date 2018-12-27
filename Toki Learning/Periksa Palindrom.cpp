#include <iostream>
using namespace std;

string str;

bool palindrome(string x)
{
    for (int a = 0, b = x.size() - 1; a < b; a++, b--)
        if (x[a] != x[b])
            return false;
    return true;
}

int main()
{
    cin >> str;
    if (palindrome(str))
        cout << str;
    while (cin >> str)
        if (palindrome(str))
            cout << " " << str;
    cout << "\n";
}
