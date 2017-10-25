#include <bits/stdc++.h>
using namespace std;

long long sieve_size;
bitset<10000000> bs;
vector<int> primes;

void sieve(long long x){
	bs.set();
	sieve_size = x;

	for(long long a = 2; a <= x; a++) if(bs[a]){

		for(long long b = a * a; b <= x; b += a)
			bs[b] = false;

		primes.push_back((int) a);
	}
}

vector<int> primeFactorsPower(long long x){
	vector<int> pfPower;

	long long pfIdx = 0, pf = primes[pfIdx];

	while((pf * pf) <= x){
		int count = 0;

		while(x % pf == 0){
			x /= pf;
			count++;
		}
		
		pfPower.push_back(count);

		pf = primes[++pfIdx];
	}

	if(x != 1) pfPower.push_back(1);

	return pfPower;
}

int main(){
	sieve(10000000);

	int N;

	while(scanf("%d", &N), N){
		int ans = 0;

		vector<int> powersCount = primeFactorsPower(N);

		for(int a = 0; a < powersCount.size(); a++){
			int count = powersCount[a];

			for(int b = a + 1; b < powersCount.size(); b++)
				count = count * ((2 * powersCount[b]) + 1);

			ans += count;
		}

		printf("%d %d\n", N, ans + 1);
	}
}
