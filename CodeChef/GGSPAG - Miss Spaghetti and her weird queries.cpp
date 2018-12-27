#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bitset<10000000> bs;
long long sieveSize;

void sieve(long long x)
{
    sieveSize = x;

    bs.set();

    bs[0] = bs[1] = 0;

    for (long long a = 2; a < x; a++)
        if (bs[a]) {
            for (long long b = a * a; b < x; b += a)
                bs[b] = 0;
            primes.push_back((int)a);
        }
}

bool isPrime(long long x)
{
    if (x <= sieveSize)
        return bs[x];

    for (int a = 0; a < primes.size(); a++)
        if (x % primes[a] == 0)
            return false;

    return true;
}

int main()
{
    sieve(1000000);

    int N, Q;

    scanf("%d %d", &N, &Q);

    vector<int> v(N);

    for (int a = 0; a < N; a++)
        scanf("%d", &v[a]);

    int type, L, R, count[1100000];

    memset(count, 0, sizeof(count));

    count[0] = isPrime(v[0]);

    for (int a = 1; a < N; a++)
        count[a] = count[a - 1] + isPrime(v[a]);

    for (int a = 0; a < Q; a++) {
        scanf("%d %d %d", &type, &L, &R);

        if (type == 1) {

            if (L > R) {
                printf("0\n");

                continue;
            }

            printf("%d\n", count[R - 1] - (L == 1 ? 0 : count[L - 2]));

        } else {

            if (isPrime(R) && !isPrime(v[L - 1])) {
                for (int a = L - 1; a < N; a++)
                    count[a]++;
            } else if (!isPrime(R) && isPrime(v[L - 1])) {
                for (int a = L - 1; a < N; a++)
                    count[a]--;
            }

            v[L - 1] = R;
        }
    }
}
