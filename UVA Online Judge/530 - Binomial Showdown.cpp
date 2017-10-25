#include <bits/stdc++.h>
using namespace std;

long long nCk(long long N, long long K){
	if(K > N) return 0;
	if(K == 0) return 1;

	long long ans = 1;

	if(N < (2 * K))
		K = N - K;

	for(long long a = 0; a < K; a++){
		ans *= (N - a);
		ans /= (a + 1);
	}

	return ans;
}

int main(){
	long long N, K;

	while(scanf("%lld %lld", &N, &K), (N | K)){
		printf("%lld\n", nCk(N, K));
	}
}
