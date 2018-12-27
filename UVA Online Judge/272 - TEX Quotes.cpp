#include <iostream>
#include <string.h>
using namespace std;

string inp;
bool temp = true;

int main()
{
    while (getline(cin, inp)) {
        for (int a = 0, sz = inp.size(); a < sz; a++) {
            if (inp[a] != '\"')
                cout << inp[a];
            else {
                if (temp) {
                    cout << "``";
                    temp = false;
                } else {
                    cout << "''";
                    temp = true;
                }
            }
        }
        cout << "\n";
    }
}
