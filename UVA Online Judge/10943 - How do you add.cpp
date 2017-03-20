#include <bits/stdc++.h>
using namespace std;

int N, K, memo[110][110];

int ways(int n, int k){
	if(k==1) return 1;
	if(memo[n][k]!=-1) return memo[n][k];
	int ans=0;
	for(int a=0;a<=n;a++)
		ans=(ans+ways(n-a, k-1))%1000000;
	return memo[n][k]=ans;
}

int main(){
	memset(memo, -1, sizeof(memo));
	while(scanf("%d %d", &N, &K), N||K){
		printf("%d\n", ways(N, K));
	}
}