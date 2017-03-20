#include <bits/stdc++.h>
using namespace std;

long long sieve_size;
vector<int> primes;
bitset<10000000> bs;

void sieve(long long x){
	sieve_size = x;

	bs.set();
	bs[0] = bs[1] = 0;

	for(long long a = 2; a <= x; a++) if(bs[a]){
		for(long long b = a * a; b <= x; b += a)
			bs[b] = 0;

		primes.push_back(a);
	}
}

int main(){
	sieve(1000000);
	long long ans = 0;

	for(int a = 0; a < primes.size(); a++)
		if(600851475143 % primes[a] == 0)
			ans = primes[a];
	
	cout << ans << "\n";
}