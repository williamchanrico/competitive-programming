#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int jmlInput, x, y, minus = 0, plus = 0;
    string str;
    vector<int> v;

    cin >> jmlInput;
    for (int a = 0; a < jmlInput; a++) {
        cin >> str;
        if (str == "add") {
            cin >> x >> y;
            for (int b = 0; b < y; b++)
                v.push_back(x);
            cout << v.size() << endl;
            plus = 0;
            minus = 0;
        } else if (str == "del") {
            cin >> x;
            cout << v[v.size() - 1] + (plus - minus) << endl;
            for (int b = 0; b < x; b++)
                v.pop_back();
        } else if (str == "adx") {
            cin >> x;
            plus += x;
        } else if (str == "dex") {
            cin >> x;
            minus += x;
        }
    }
}