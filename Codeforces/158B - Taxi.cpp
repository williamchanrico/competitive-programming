#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> v(5, 0);
long long n, temp, ans = 0;

int main()
{
    cin >> n;
    for (long long a = 0; a < n; a++) {
        cin >> temp;
        if (temp == 4)
            ans++;
        else
            v[temp]++;
    }
    ans += min(v[3], v[1]);
    ans += ceil(v[2] / 2.0);
    if (v[3] > v[1]) {
        v[3] -= v[1];
        ans += v[3];
    } else if (v[3] < v[1]) {
        v[1] -= v[3];
        if (v[2] % 2 == 1)
            ans += (v[1] - 2 >= 0) ? ceil((v[1] - 2) / 4.0) : 0;
        else
            ans += ceil(v[1] / 4.0);
    }
    cout << ans << "\n";
}