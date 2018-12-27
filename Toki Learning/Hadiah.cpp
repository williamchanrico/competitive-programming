#include <map>
#include <stdio.h>
#include <vector>
using namespace std;

map<int, bool> m;
vector<long long> v;
long long A, B, C, D;

long long pangkat(long long x, long long y, long long mod)
{
    if (y == 0)
        return 1 % mod;
    if (y == 1)
        return x % mod;
    long long ret = pangkat(x, y / 2, mod);
    ret = (ret * ret) % mod;
    if (y % 2)
        ret *= x;
    return ret % mod;
}

int main()
{
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
    long long nA = 1 % D;
    while (!m.count(nA)) {
        v.push_back(nA);
        m[nA] = true;
        nA = (nA * A) % D;
    }
    long long len = v.size();
    long long idx = 0;
    while (v[idx] != nA)
        ++idx;
    long long ModPangkat = len - idx;
    long long nB = 1;
    bool breaked = false;
    for (long long a = 0; a < C; a++) {
        nB = (nB * B);
        if (nB > len) {
            breaked = true;
            break;
        }
    }
    if (!breaked) {
        printf("%lld\n", v[nB] + 1);
    } else {
        long long tmp = pangkat(B, C, ModPangkat);
        for (long long a = idx; a < len; a++)
            if (a % ModPangkat == tmp) {
                printf("%lld\n", v[a] + 1);
                break;
            }
    }
}