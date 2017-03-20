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

		primes.push_back((int) a);
	}
}

int main(){
	sieve(105000);
	
	cout << primes[10000] << "\n";
}