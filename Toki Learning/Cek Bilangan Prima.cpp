#include <bitset>
#include <stdio.h>
#include <vector>
using namespace std;

long long sieve_size, inp;
vector<int> primes;
bitset<10000001> bs;

void sieve(long long x)
{
    sieve_size = x;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long a = 2; a <= sieve_size; a++)
        if (bs[a]) {
            for (long long b = a * a; b <= sieve_size; b += a)
                bs[b] = 0;
            primes.push_back(a);
        }
}

bool isPrime(long long x)
{
    if (x < 0)
        return false;
    if (x <= sieve_size)
        return bs[x];
    for (int a = 0, sz = primes.size(); a < sz; a++)
        if (x % primes[a] == 0)
            return false;
    return true;
}

int main()
{
    sieve(1000000);
    while (scanf("%d", &inp) != EOF)
        printf("%s\n", (isPrime(inp)) ? "YA" : "TIDAK");
}
