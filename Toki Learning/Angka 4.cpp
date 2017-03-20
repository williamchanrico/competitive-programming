#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bitset<1000000> bs;
long long sieve_size;
int n, q, ans=0;

void sieve(long long x){
	sieve_size=x;
	bs.set(); bs[0]=bs[1]=0;
	for(long long a=2;a<=sieve_size;a++) if(bs[a]){
		primes.push_back((int)a);
		for(long long b=a*a;b<=sieve_size;b+=a) bs[b]=0;
	}
}

bool isPrime(long long x){
	if(x<=sieve_size) return bs[x];
	for(int a=0, sz=primes.size();a<sz;a++)
		if(x%primes[a]==0) return false;
	return true;
}

int main(){
	sieve(1000000);
	cin >> n >> q;
	for(int a=n;a<=q;a++)
		if(!isPrime(a) && a!=1) ans++;
	cout << ans << "\n";
}
