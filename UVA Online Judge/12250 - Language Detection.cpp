#include <iostream>
using namespace std;

int main()
{
    string inp;
    int n = 1;
    cin >> inp;
    while (inp != "#") {
        if (inp == "HELLO")
            cout << "Case " << n << ": "
                 << "ENGLISH\n";
        else if (inp == "HOLA")
            cout << "Case " << n << ": "
                 << "SPANISH\n";
        else if (inp == "HALLO")
            cout << "Case " << n << ": "
                 << "GERMAN\n";
        else if (inp == "BONJOUR")
            cout << "Case " << n << ": "
                 << "FRENCH\n";
        else if (inp == "CIAO")
            cout << "Case " << n << ": "
                 << "ITALIAN\n";
        else if (inp == "ZDRAVSTVUJTE")
            cout << "Case " << n << ": "
                 << "RUSSIAN\n";
        else
            cout << "Case " << n << ": "
                 << "UNKNOWN\n";
        n++;
        cin >> inp;
    }
}