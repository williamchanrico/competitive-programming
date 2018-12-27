#include <iomanip>
#include <iostream>
using namespace std;

int n;
double inp, mins = 1000001, maks = -1000001, rata2, jmlh = 0;

int main()
{
    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> inp;
        jmlh += inp;
        mins = min(mins, inp);
        maks = max(maks, inp);
    }
    rata2 = jmlh / n;
    cout << fixed << setprecision(2) << mins << " " << maks << " " << rata2 << "\n";
}
