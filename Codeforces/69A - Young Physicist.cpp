#include <iostream>
using namespace std;

long long n;
long long temp1, temp2, temp3;
long long ans1 = 0, ans2 = 0, ans3 = 0;

int main()
{
    cin >> n;
    while (n--) {
        cin >> temp1 >> temp2 >> temp3;
        ans1 += temp1;
        ans2 += temp2;
        ans3 += temp3;
    }
    if (ans1 || ans2 || ans3)
        cout << "NO\n";
    else
        cout << "YES\n";
}
