#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
using namespace std;

vector<int> primes;
bitset<10000001> bs;
long long sieve_size, n, m, ans;

void sieve(long long x){
	sieve_size=x;
	bs.set(); bs[0]=bs[1]=0;
	for(long long a=2;a<=sieve_size;a++) if(bs[a]){
		for(long long b=a*a;b<=sieve_size;b+=a) bs[b]=0;
		primes.push_back((int)a);
	}
}

bool isPrime(long long x){
	if(x<=sieve_size) return bs[x];
	for(int a=0, sz=primes.size();a<sz;a++)
		if(x%primes[a]==0) return false;
	return true;
}

int main(){
	bool ada=false;
	sieve(1000000);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(long long a=n;a<=m;a++)
		for(long long b=(a==n?a+1:n);b<=m;b++)
			if(isPrime(a) && isPrime(b)){
				stringstream s;
				s << a << b;
				s >> ans; //cout << "ans = " << ans << "  isPrime(" << ans << ") = " << isPrime(ans) << "\n";
				if(isPrime(ans)){ cout << a << " " << b << "\n"; ada=true; }
			}
	if(!ada) cout << "TIDAK ADA\n";
}