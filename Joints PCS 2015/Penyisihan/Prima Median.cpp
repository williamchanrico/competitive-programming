// Fors

#include <bits/stdc++.h>
using namespace std;

bitset<1000010> bs;
vector<int> prime;
long long sieve_size;

long long sieve(long long x)
{
    sieve_size = x;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long a = 2; a <= x; a++)
        if (bs[a]) {
            for (long long b = a + a; b <= x; b += a)
                bs[b] = 0;
            prime.push_back((int)a);
        }
}

int main()
{
    sieve(1000000);
    long long L, R;
    long long left = 0, right = 78497, mid;

    cin >> L >> R;

    while (prime[left] < L)
        left++;

    while (prime[right] > R)
        right--;

    if (left > right) {
        cout << "0\n";
        return 0;
    }

    int tmp;
    vector<int> v, temp;
    for (long long a = left; a <= right; a++) {
        tmp = prime[a];

        while (tmp > 0) {
            temp.push_back(tmp % 10);
            tmp /= 10;
        }

        for (int b = temp.size() - 1; b > -1; b--)
            v.push_back(temp[b]);
        temp.clear();
    }

    tmp = v.size();

    if (tmp % 2 == 0)
        cout << (v[(tmp - 1) / 2] + v[tmp / 2]) / 2 << "\n";
    else
        cout << v[tmp / 2] << "\n";
}