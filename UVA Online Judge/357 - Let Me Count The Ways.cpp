#include <bits/stdc++.h>
using namespace std;

long long inp, dp[8][30010], coins[]={1, 5, 10, 25, 50};

long long ways(int id, int rem){
	if(rem==0) return 1;
	if(rem<0 || id==5) return 0;
	if(dp[id][rem]!=-1) return dp[id][rem];
	return dp[id][rem]=ways(id+1, rem)+ways(id, rem-coins[id]);
}

int main(){
	memset(dp, -1, sizeof(dp));
	while(scanf("%lld", &inp)!=EOF){
		long long ans=ways(0, inp);
		if(ans==1) printf("There is only %lld way to produce %lld cents change.\n", ans, inp);
		else printf("There are %lld ways to produce %lld cents change.\n", ans, inp);
	}
}