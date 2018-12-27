#include <bitset>
#include <stdio.h>
#include <vector>
using namespace std;

long long sieve_size;
vector<int> primes;
bitset<10000010> bs;

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

int main()
{
    sieve(1000000);
    long long T, inp;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &inp);
        printf("%d\n", primes[inp - 1]);
    }
}