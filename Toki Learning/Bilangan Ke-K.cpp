#include <bits/stdc++.h>
using namespace std;

long long N, K, data[100005];

bool cmp(long long x, long long y){
	return x>y;
}

int main(){
	scanf("%lld %lld", &N, &K);
	for(int a=0;a<N;a++)
		scanf("%lld", &data[a]);
	sort(data, data+N, cmp);
	printf("%lld\n", data[K-1]);
}