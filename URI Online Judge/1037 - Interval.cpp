#include <bits/stdc++.h>
using namespace std;

int main()
{
    double inp;
    scanf("%lf", &inp);
    if (inp < 0 || inp > 100) {
        cout << "Fora de intervalo\n";
        return 0;
    }
    if (inp <= 25)
        cout << "Intervalo [0,25]\n";
    else if (inp <= 50)
        cout << "Intervalo (25,50]\n";
    else if (inp <= 75)
        cout << "Intervalo (50,75]\n";
    else if (inp <= 100)
        cout << "Intervalo (75,100]\n";
}