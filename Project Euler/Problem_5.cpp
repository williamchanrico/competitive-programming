#include <bits/stdc++.h>
using namespace std;

long long sieve_size;
vector<int> primes;
vector<int> factors;
bitset<10000000> bs;

void sieve(long long x)
{
    sieve_size = x;

    bs.set();
    bs[0] = bs[1] = 0;

    for (long long a = 2; a <= x; a++)
        if (bs[a]) {
            for (long long b = a * a; b <= x; b += a)
                bs[b] = 0;

            primes.push_back((int)a);
        }
}

map<int, int> primeFactors(long long x)
{
    map<int, int> m;
    int idx_PF = 0, PF = primes[idx_PF];

    while (PF * PF <= x) {
        while (x % PF == 0) {
            if (!m.count(PF))
                m[PF] = 1;
            else
                m[PF]++;
            x /= PF;
        }

        PF = primes[++idx_PF];
    }

    if (x != 1) {
        if (!m.count(x))
            m[x] = 1;
        else
            m[x]++;
    }

    return m;
}

int main()
{
    sieve(1000000);
    map<int, int> ans1;
    int ans2 = 1;
    int n;

    cin >> n;

    for (int a = 1; a <= n; a++) {
        map<int, int> m = primeFactors(a);
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (!ans1.count(it->first))
                ans1[it->first] = 1;
            else
                ans1[it->first] = max(ans1[it->first], it->second);
        }
    }

    cout << "Faktor-faktor prima terbesar dari bilangan 1->" << n << " :\n";

    for (map<int, int>::iterator it = ans1.begin(); it != ans1.end(); it++) {
        cout << it->first << "^" << it->second << "\n";
        ans2 *= pow(it->first, it->second);
    }

    cout << "Hasil perkalian faktor-faktor prima tersebut = " << ans2 << "\n";
}