#include <stdio.h>
#include <map>
#include <vector>
#include <bitset>
using namespace std;

vector<int> primes;
bitset<10000010> bs;
map<int, int> PF;
long long sieve_size;

void sieve(long long x){
	sieve_size=x;
	bs.set();
	bs[0]=bs[1]=0;
	for(long long a=2;a<=sieve_size;a++) if(bs[a]){
		for(long long b=a*a;b<=sieve_size;b+=a) bs[b]=0;
		primes.push_back((int)a);
	}
}

void PrimeFactor(long long x){
	long long PF_idx=0, pf=primes[0];
	while(pf*pf <= x){
		while(x%pf==0) {x/=pf; PF[pf]++;}
		pf=primes[++PF_idx];
	}
	if(x!=1) PF[x]++;
}

int main(){
	sieve(10000000);
	long long inp;
	scanf("%lld", &inp);
	PrimeFactor(inp);
	for(map<int, int>::iterator it=PF.begin();it!=PF.end();it++){
		if(it==PF.begin()){
			if(it->second != 1)
				printf("%d^%d", it->first, it->second);
			else
				printf("%d", it->first, it->second);
		}else{
			if(it->second != 1)
				printf(" x %d^%d", it->first, it->second);
			else
				printf(" x %d", it->first, it->second);
		}
	}
	printf("\n");
}