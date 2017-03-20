#include <stdio.h>
#include <vector>
using namespace std;

vector<long long> v;
long long N;

void hitung(long long x, long long y){
	if(x<=N)
		hitung(x*3, y);
	else
		return;
	if(N>=x){
		v.push_back(x);
		N-=x;
	}
	if(N==0) return;
}

int main(){
	scanf("%lld", &N);
	hitung(1, N);
	printf("%d\n", v.size());
	for(int a=v.size()-1;a>-1;a--)
		if(a==0) printf("%lld\n", v[a]);
		else printf("%lld ", v[a]);
}
